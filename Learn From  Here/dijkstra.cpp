#include<bits/stdc++.h>
using namespace std;

// MyTask
#define N 200005
bool vis[N];
vector<pair<int,int>>adj_list[N];
vector<int>costs(N,N),parent(N);

int pathfind(int source,int dest){
    if(dest!=source && parent[dest]==-1){
        cout<<"Path Not Found"<<endl;
        return 0;
    }
    if(dest==source){
        cout<<source;
        return 0;
    }
    pathfind(source,parent[dest]);
    cout<<"->"<<dest;
}


// dijakstra (single source shortest path algo)
void dijkstra(int node,int initial_cost){
    priority_queue<pair<int,int>>pq;
    pq.push({-initial_cost,node}); // -cost,node
    costs[node]=initial_cost;
    while(!pq.empty()){
        pair<int,int> frontpair=pq.top();
        pq.pop();
        int cost=-frontpair.first,front=frontpair.second;
        if(cost>costs[front]) continue;
        for(int i=0;i<adj_list[front].size();i++){
            pair<int,int> child=adj_list[front][i];
            if(costs[front]+child.second<costs[child.first]){
                costs[child.first]=costs[front]+child.second;
                parent[child.first]=front;
                pq.push({-costs[child.first],child.first});
            }
        }
    }
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,cost; cin>>x>>y>>cost;
        adj_list[x].push_back({y,cost});
    }
    cout<<"dijsktra: "<<endl;
    dijkstra(1,0);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<": "<<endl;
    //     for(int j=0;j<adj_list[i].size();j++){
    //         cout<<adj_list[i][j].first<<" "<<adj_list[i][j].second<<endl;
    //     }
    // }
    for(int i=1;i<=n;i++){
        cout<<"cost: "<<costs[i]<<" to reach at "<<i<<endl;
        cout<<"the path is: "; pathfind(1,i); cout<<endl;
    }
    return 0;
}

