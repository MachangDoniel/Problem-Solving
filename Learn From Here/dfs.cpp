#include<bits/stdc++.h>
using namespace std;

// MyTask
#define N 200005
bool vis[N];
vector<int>adj_list[N];

void dfs(int parent){
    vis[parent]=true;
    cout<<parent<<" ";
    for(int child:adj_list[parent]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    cout<<"DFS : ";
    dfs(1);

    return 0;
}