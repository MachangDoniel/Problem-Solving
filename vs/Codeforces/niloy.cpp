#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll N=1e5+7;
vector<ll>parent(N),Size(N),edges(N);

void Make(ll i)
{
    parent[i]=i;
    Size[i]=1;
}

ll Find(ll v)
{
    if(parent[v]==v)return v;
    return parent[v]=Find(parent[v]);
}

void Union(ll u,ll v)
{
    u=Find(u);
    v=Find(v);

    if(u!=v)
    {
        if(Size[v]<Size[u])swap(u,v);
        parent[u]=v;
        Size[v]+=Size[u];
    }
}

int main()
{
    ll i,j,k,l,m,n,res=0,u,v;
    cin>>n>>m;
    map<ll,set<ll>>mp;
    for(i=1;i<=n;i++)
    {
        Make(i);
    }
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        Union(u,v);
        edges[u]++;
        edges[v]++;
    }
    for(i=1;i<=n;i++)
    {
        mp[Find(i)].insert(i);
    }
    for(auto it:mp)
    {
        set<ll>st;
        ll nodes=0;
        st=it.second;
        //cout<<it.first<<"   ";
        for(auto itt:st)
        {
            if(edges[itt]==2)nodes++;
           // cout<<itt<<" ";
        }
        //cout<<endl;
        if(nodes==st.size())res++;
    }
    cout<<res<<endl;
    return 0;
}
