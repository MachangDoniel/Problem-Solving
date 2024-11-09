// Standard Library Headers
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
using namespace std;
// MyTask

void solve() {
    // ll in, n, m, i, j, k, x, y;
    int n,m; cin>>n>>m;
    vector<vector<int>>adj(n);
    set<pair<int,int>>s;
    map<int,int>mp;
    vector<int>in(n,0);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        u--, v--;
        in[v]++;
        adj[u].push_back(v);
        mp[v]++;
    }
    int count=n-mp.size();
    for(int i=0;i<n;i++){
        s.insert({in[i],i});
    }
    // for(auto it:s){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    map<int,int>out;
    while(!s.empty()){
        int ff=s.begin()->first;
        int ss=s.begin()->second;
        s.erase(s.begin());
        if(ff){
            count++;
        }
        out[ss]++;
        for(int i=0;i<adj[ss].size();i++){
            int v=adj[ss][i];
            if(out[v]==0){
                s.erase({in[v],v});
                in[v]=0;
                s.insert({in[v],v});
                break;
            }
        }
    }
    cout<<count<<endl;
}

int main() {
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
