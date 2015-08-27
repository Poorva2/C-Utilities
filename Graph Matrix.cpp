/*
* Graph with n nodes numbered 1 to n in adjacency matrix representation
*/
#include<iostream>
#include <vector>
#define INF 0b111111111111111111111111111111  //So that value does not overflow in floyd warshall
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
template <typename T>
class Graph
{
    vector<vector<T> > matrix;
    int numberOfNodes;
public:
    Graph(int n = 0)
    {
        numberOfNodes = n;
        vector<T> v(n+1,INF);
        for(int i =0; i<=n;i++)
        {
            matrix.push_back(v);
        }
    }
    void printGraph()
    {
        int i,j;
        cout<<endl<<endl;
        for(i=1;i<=numberOfNodes;i++)
        {
            for(j=1;j<=numberOfNodes;j++)
            {
                cout<<matrix[i][j]<<" \t ";
            }
            cout<<endl;
        }
    }
    void addNode()
    {
        for(int i = 0; i<=numberOfNodes;i++)
        {
            matrix[i].push_back(INF);
        }
        numberOfNodes++;
        vector<T> v(numberOfNodes,INF);
        matrix.push_back(v);
    }
    void addEdge_unidirectional(int x, int y, T weight = 1)
    {
        if(x<1||x>numberOfNodes||y<1||y>numberOfNodes)
        {
            cout<<"Invalid nodes";
            return;
        }
        if(matrix[x][y]!=INF)
        {
            cout<<"Edge already exists";
            return;
        }
        matrix[x][y] = weight;
    }
    void addEdge_bidirectional(int x, int y, T weight = 1)
    {
        if(x<1||x>numberOfNodes||y<1||y>numberOfNodes)
        {
            cout<<"Invalid nodes";
            return;
        }
        if(matrix[x][y]!=INF)
        {
            cout<<"Edge already exists";
            return;
        }
        matrix[x][y] = weight;
        matrix[y][x] = weight;
    }
    void BFS(int start,vector<int>& dist)
    {
        int indexCurrent;
        dist.clear();
        for(int i=0;i<=numberOfNodes;i++)
            dist.push_back(INF);
        dist[start] = 0;
        int q[numberOfNodes],first=0,last=0;
        q[last++] = start;
        while(first!=last)
        {
            indexCurrent = q[first++];
            for(int i=1; i<=numberOfNodes; i++)
            {
                if(matrix[indexCurrent][i]!=INF)
                {
                    if(dist[i]==INF)
                    {
                        q[last++] = i;
                        dist[i] = dist[indexCurrent]+1;
                    }
                }
            }
        }
    }
    void floydWarshall(vector<vector<T> >& dist)
        {
            int i,j,k;
            dist = (this->matrix);
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

};
int main()
{
    Graph<int> g(4);
    g.addNode();
    for(int i =1;i<=4;i++)
    g.addEdge_unidirectional(i,i+1);
    g.addEdge_bidirectional(1,3);
    g.printGraph();
    vector<vector<int> > v;
    g.floydWarshall(v);
    vector<int> dist;
    g.BFS(1,dist);
    for(int i=1; i<dist.size();i++)
        cout<<dist[i]<<" ";
}
