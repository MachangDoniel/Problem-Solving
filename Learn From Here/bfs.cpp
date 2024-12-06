#include<bits/stdc++.h>
using namespace std;

// MyTask
const int N=200005;
bool vis[N];
vector<int>adj_list[N];

void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=true;
    while(!q.empty()){
        int parent=q.front();
        cout<<"Children of "<<parent<<": ";
        q.pop();
        for(int child:adj_list[parent]){
            if(!vis[child]){
                cout<<child<<" ";
                q.push(child);
                vis[child]=true;
            }
        }
        cout<<endl;
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
    cout<<"BFS: "<<endl;
    bfs(1);

    return 0;
}