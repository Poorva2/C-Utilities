/*
* Graph with n nodes numbered 1 to n
*/
#include<iostream>
#include<vector>
#include<queue>
#define INF (0b111111111111111111111111111111)
#define ll                  long long int
#define MOD                 1000000007
#define repi(i,x,y)         for(i=x;i<=y;i++)
#define invrepi(i,x,y)      for(i=x;i>=y;i--)
#define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;

using namespace std;
class Edge
{
    int destination;

    public:

    double weight;
    Edge(int d, double w=1)
    {
        weight = w;
        destination = d;
    }
    void printEdge()
    {
        cout<<destination<<" with weight "<<weight<<endl;
    }
    int getDest()
    {
        return destination;
    }
    bool operator<(const Edge& otherEdge) const
    {
        return weight<otherEdge.weight;
    }
};
class Node
{
    public:
    int val;
    vector<Edge> outEdges;
    Node(int v = 0)
    {
        val = v;
    }
    void printAllEdges()
    {
        for(vector<Edge>::iterator itr = outEdges.begin();itr!=outEdges.end();itr++)
        {
            cout<<"\t";
            (*itr).printEdge();
            cout<<endl;
        }
    }
};
class MyComparision
{
    vector<double>& dist;
    public:

        MyComparision(vector<double>& d):
        dist(d){}

        bool operator() (const int& a,const int& b)
        {
            return dist[a]>dist[b];
        }
};
bool lessThanEdge(const Edge& e1,const Edge& e2)
{
    return e1.weight<e2.weight;
}
class Graph
{
    private:
        vector<Node> nodes;
        int numberOfNodes;

        void dfs_visit(int start,bool visited[])
        {
            //cout<<"Visiting "<<start<<endl;
            visited[start]=true;
            for(vector<Edge>::iterator itr=nodes[start].outEdges.begin();itr!=nodes[start].outEdges.end();itr++)
            {
                if(!visited[itr->getDest()])
                {
                    dfs_visit(itr->getDest(),visited);
                }
            }
        }

    public:
        Graph(int n = 0)
        {
            numberOfNodes = -1;
            addNode(INF);   //Dummy node so that actual graph is from 1..numberOfNodes.
            for(int i=1;i<=n;i++)
                addNode(0);
        }
        void destroy()
        {
            nodes.clear();
            numberOfNodes = -1;
            addNode(INF);   //Dummy node so that actual graph is from 1..numberOfNodes.
        }
        int getNumberOfNodes()
        {
            return numberOfNodes;
        }
        int getVal(int index)
        {
            return nodes[index].val;
        }
        double edgeWeight(int i,int j)
        {
            if(i<1||j<1||i>numberOfNodes||j>numberOfNodes)
            {
                cout<<"Invalid nodes"<<endl;
            }
            if(i==j)
                return 0;
            for(vector<Edge>::iterator itr = nodes[i].outEdges.begin();itr!= nodes[i].outEdges.end();itr++)
            {
                if(itr->getDest()==j)
                    return itr->weight;
            }
            return INF;
        }
        void addNode(const int& val)
        {
            nodes.push_back(Node(val));
            numberOfNodes++;
        }
        void addEdge_unidirectional(const int& from, const int& to, double weight = 1)
        {
            if(from>numberOfNodes||to>numberOfNodes)
            {
                cout<<"Invalid Node! Nodes are numbered from 1 to "<<numberOfNodes<<endl;
                return;
            }
            nodes[from].outEdges.push_back(Edge(to , weight));
        }
        void addEdge_bidirectional(const int& from, const int& to, double weight =1)
        {
            if(from>numberOfNodes||to>numberOfNodes)
            {
                cout<<"Invalid Node! Nodes are numbered from 1 to "<<numberOfNodes<<endl;
                return;
            }
            nodes[from].outEdges.push_back(Edge(to , weight));
            nodes[to].outEdges.push_back(Edge(from , weight));
        }
        void printGraph()
        {
            cout<<"No. of Nodes = "<<numberOfNodes<<endl<<endl;
            for(int i = 1; i<=numberOfNodes; i++)
            {
                cout<<i<<"(Value = "<<nodes[i].val<<") -> "<<endl;
                nodes[i].printAllEdges();
            }
        }
        void BFS(int start,vector<int>& dist)
        {
            int indexCurrent;
            dist.clear();
            for(int i=0;i<=numberOfNodes;i++)
                dist.push_back(INF);
            dist[start] = 0;
            queue<int> q;
            q.push(start);
            while(!q.empty())
            {
                indexCurrent = q.front();
                q.pop();
                for(vector<Edge>::iterator itr = (nodes[indexCurrent]).outEdges.begin();itr!=nodes[indexCurrent].outEdges.end();itr++)
                {
                    if(dist[itr->getDest()]==INF)
                    {
                        q.push(itr->getDest());
                        dist[itr->getDest()] = dist[indexCurrent]+1;
                    }
                }
            }
        }
        void dfs(int x = -1)
        {
            if(x!=-1&&(x<1||x>numberOfNodes))
            {
                cout<<"Invalid Node! Nodes are numbered from 1 to "<<numberOfNodes<<endl;
                return;
            }
            bool visited[numberOfNodes+1];
            for(int i=1;i<=numberOfNodes;i++)
                visited[i] = false;
            if(x==-1)
            {
                //Go through all nodes once
                for(int i=1;i<=numberOfNodes;i++)
                    if(!visited[i])
                        dfs_visit(i,visited);
                return;
            }
            dfs_visit(x,visited);
        }
        void djikstras(int start, vector<double>& dist)
        {
            int index;
            dist.clear();
            for(int i = 0;i<numberOfNodes+1;i++)
                dist.push_back(INF);
            dist[start] = 0;
            MyComparision comp(dist);
            priority_queue<int,vector<int>, MyComparision > q(comp);
            q.push(start);
            while(!q.empty())
            {
                index = q.top();
                q.pop();
                for(vector<Edge>::iterator itr = nodes[index].outEdges.begin();itr!=nodes[index].outEdges.end();itr++)
                {
                    if(dist[itr->getDest()] == INF)
                        q.push(itr->getDest());
                    if(dist[itr->getDest()]>dist[index]+itr->weight)
                        dist[itr->getDest()] = dist[index]+itr->weight;
                }
            }
        }

        void floydWarshall(vector<vector<double> >& dist)
        {
            int i,j,k;
            dist.clear();
            for(i=0;i<=numberOfNodes;i++)
            {
                vector<double> v(numberOfNodes+1,INF);
                dist.push_back(v);
            }
            for(i=1;i<=numberOfNodes;i++)
            {
                for(j=1;j<=numberOfNodes;j++)
                {
                    dist[i][j]=edgeWeight(i,j);
                }
            }
            for(k=1;k<=numberOfNodes;k++)
            {
                for(i=1;i<=numberOfNodes;i++)
                {
                    for(j=1;j<=numberOfNodes;j++)
                    {
                        if(dist[i][k]+dist[k][j]<dist[i][j])
                           dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        /*
        This is not the correct Algo
        void PrimMST(Graph& MST)
        {
            int i;
            MST.destroy();
            for(i=1;i<=numberOfNodes;i++)
                MST.addNode(nodes[i].val);
            priority_queue<Edge> minheapEdge;
            vector<Edge>::iterator itr;
            Edge toBeAdded(1);                  //One is passed as there is no default constructor
            bool addedVertex[numberOfNodes+1];
            for(i=1;i<=numberOfNodes;i++)
                addedVertex[i] = false;
            addedVertex[1] = true;
            for(itr=nodes[1].outEdges.begin();itr!=nodes[1].outEdges.end();itr++)
                minheapEdge.push(*itr);
            while(!minheapEdge.empty())
            {
                toBeAdded = minheapEdge.top();
                minheapEdge.pop();
                MST.addEdge_bidirectional(toBeAdded.)

            }
        }
        */

};
int main()
{
    Graph g(5);
    g.addEdge_bidirectional(1,2,10);
    g.addEdge_bidirectional(2,3,1);
    g.addEdge_bidirectional(3,4,1);
    g.addEdge_bidirectional(4,5,3);
    g.addEdge_bidirectional(1,5,18);
    g.addEdge_bidirectional(4,2,4);
    g.printGraph();
    vector<vector<double> > distfw;
    vector<double> distdj;
    g.BFS(1,dist);
}
