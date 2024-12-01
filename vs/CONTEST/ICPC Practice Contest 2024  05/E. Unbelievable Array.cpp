#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 100005;

int n,q,parent[N],sz[N],ans[N],parent_value[N];
vector<int>graph[N];

void init(int n){
    for(int i=0;i<n;i++) parent[i]=i, sz[i]=1;
}

int find_sets(int a){
    if(parent[a]==a) return a;
    return parent[a]=find_sets(parent[a]); //path compression
}

void union_sets(int a, int b){
    a=find_sets(a), b=find_sets(b);
    if(a==b) return;
    if(sz[a]>sz[b]) swap(a,b); //size compression
    if(a!=b) parent[a]=b, sz[b]+=sz[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    int test=1;
    while(t--){
        init(N);
        for(int i=0;i<N;i++){
            graph[i].clear();
            parent_value[i]=-1;
        }
        cin>>n>>q;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            graph[v[i]].push_back(i);
        }
        for(int i=0;i<N;i++){
            int num=graph[i].size();
            int flag=-1;
            if(num) flag=graph[i][0];
            for(int j=1; j<num; j++){
                union_sets(graph[i][j-1],graph[i][j]);
            }
            if(flag!=-1){
                int par=find_sets(flag);
                ans[par]=i;
                parent_value[i]=par;
            }
        }
        cout<<"Case "<<test++<<":"<<endl;
        while(q--){
            int c;
            cin>>c;
            if(c==1){
                int x, y;
                cin>>x>>y;
                if(x==y) continue;
                int pvx=parent_value[x], pvy=parent_value[y];
                if(pvx!=-1){
                    if(pvy==-1){
                        parent_value[y]=pvx;
                        parent_value[x]=-1;
                        ans[pvx]=y;
                    }
                    else{
                        union_sets(pvx,pvy);
                        int par=find_sets(pvx);
                        parent_value[y]=par;
                        parent_value[x]=-1;
                        ans[par]=y;
                    }
                }
            }
            else{
                int ind;
                cin>>ind;
                ind--;
                int par=find_sets(ind);
                cout<<ans[par]<<endl;
            }
        }

    }
    return 0;
}