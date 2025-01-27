// solution 1

// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include<cstring> // extra added
// using namespace std;

// #define pb push_back
// #define pp pop_back

// int n,m,adj[11][11],stack[11],ans[11],idx,minCycleSum=200005;
// int vis[11];

// void detectCycle(int node,int index){
//     if(vis[node]){
//         int sum=node;
//         for(int i=index-2;i>=0 && stack[i]!=node;i--){
//             sum+=stack[i];
//         }
//         if(sum<minCycleSum){
//             idx=0;
//             ans[idx++]=node;
//             for(int i=index-2;i>=0 && stack[i]!=node;i--){
//                 ans[idx++]=stack[i];
//             }
//         }
//         return;
//     }
//     else{
//         vis[node]=1;
//         for(int i=1;i<=n;i++){
//             if(adj[node][i]==1){
//                 stack[index]=i;
//                 detectCycle(i,index+1);
//             }
//         }
//         vis[node]=0;
//     }
// }

// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     cin>>n>>m;
//     memset(&adj[0][0],0,(n+1)*(n+1)*sizeof(int));
//     memset(vis,0,(n+1)*sizeof(int));
//     for(int i=0;i<m;i++){
//         int u,v; cin>>u>>v;
//         adj[u][v]=1;
//     }
//     for(int i=1;i<=n;i++){
//         stack[0]=i;
//         detectCycle(i,1);
//     }
//     sort(ans,ans+idx);
//     for(int i=0;i<idx;i++){
//         cout<<ans[i]<<" ";
//     }
//     // cout<<n<<m<<endl;
//     cout<<endl;
//     return 0;
// }



// solution 2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define pp pop_back
vector<vector<int>>adj;
int n,m,idx,minCycleSum=200005;
vector<int>vis,stack,ans;

void detectCycle(int node,int index){
    if(vis[node]){
        int sum=node;
        for(int i=index-2;i>=0 && stack[i]!=node;i--){
            sum+=stack[i];
        }
        if(sum<minCycleSum){
            idx=0;
            ans[idx++]=node;
            for(int i=index-2;i>=0 && stack[i]!=node;i--){
                ans[idx++]=stack[i];
            }
        }
        return;
    }
    else{
        vis[node]=1;
        for(int num:adj[node]){
            stack[index]=num;
            detectCycle(num,index+1);
        }
        vis[node]=0;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,0);
    stack.resize(n+1);
    ans.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
    }
    for(int i=1;i<=n;i++){
        stack[0]=i;
        detectCycle(i,1);
    }
    sort(ans.begin(),ans.begin()+idx);
    for(int i=0;i<idx;i++){
        cout<<ans[i]<<" ";
    }
    // cout<<n<<m<<endl;
    cout<<endl;
    return 0;
}
