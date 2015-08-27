#include<iostream>
#include<vector>
#define ll long long int
#define repi(i,x,y) for(i=x;i<=y;i++)
using namespace std;
class DisjointSets
{
public:
    vector<pair<ll,ll> > v;//Set representator,Size of set
    DisjointSets(ll n)
    {
        int i;
        repi(i,0,n-1)
        {
            v.push_back(make_pair(i,1));
        }
    }
    void clearSets()
    {
        v.clear();
    }
    ll find_set(ll x)
    {
        if(v[x].first==x)
            return x;
        return v[x].first=find_set(v[x].first);
    }
    bool isSameSet(ll x, ll y)
    {
        return find_set(x)==find_set(y);
    }
    void joinSet(ll x, ll y)
    {
        if(find_set(x)==find_set(y))
            return;
        v[find_set(y)].second += v[find_set(x)].second;
        v[find_set(x)].first = find_set(y);
    }
};
