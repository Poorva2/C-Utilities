
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string.h>

using namespace std;

#define ll                  long long int
#define INF                 999999999999999999
#define MOD                 1000000007
#define repi(i,x,y)         for(i=x;i<=y;i++)
#define invrepi(i,x,y)      for(i=x;i>=y;i--)
#define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;

class Node
{
public:
    int data;
    Node(int n):data(n){}
    int getVal() const             //Must Return the Value WHICH IS USED TO DO COMPARISION TO MAKE BST
    {
        return data;
    }
    friend bool operator<=(const Node& first,const Node& second)
    {
        return first.getVal()<=second.getVal();
    }
};
class BSTNode
{
public:
    Node dataNode;
    BSTNode *left, *right;
    BSTNode(Node n):dataNode(n),left(0),right(0){}
    Node getData()
    {
        return dataNode;
    }
};
class BST
{
    BSTNode *root;
    void printUtil(BSTNode *pointer)
    {
        cout<<(pointer->getData()).getVal()<<" --> ";
        if(pointer->left != 0)
            cout<<(pointer->left->getData()).getVal()<<"        |        ";
        else
            cout<<"null"<<"        |        ";
        if(pointer->right != 0)
            cout<<(pointer->right->getData()).getVal()<<endl;
        else
            cout<<"null"<<endl;
        if(pointer->left != 0)
            printUtil(pointer->left);
        if(pointer->right != 0)
            printUtil(pointer->right);
    }
public:
    BST():root(0){}
    void add(Node n)
    {
        if(root == 0)
        {
            root = new BSTNode(n);
            return;
        }
        BSTNode *pointer = root;
        while(true)
        {
            if(n <= pointer->getData())
            {
                if(pointer->left != 0)
                {
                    pointer = pointer->left;
                    continue;
                }
                else
                {
                    pointer->left = new BSTNode(n);
                    return;
                }
            }
            else
            {
                if(pointer->right != 0)
                {
                    pointer = pointer->right;
                    continue;
                }
                else
                {
                    pointer->right = new BSTNode(n);
                    return;
                }
            }
        }
    }
    void delete(Node n)
    {
        
    }
    void print()
    {
        if(root==0)
        {
            cout<<"The BST is empty"<<endl;
            return;
        }
        cout<<"The tree is as follows************************************"<<endl;
        printUtil(root);
        cout<<"**********************************************************"<<endl;
    }
};
int main()
{
    BST bst;
    bst.add(2);
    bst.add(1);
    bst.add(3);
    bst.add(4);
    bst.print();
}
