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
#define ll long long
// MyTask

int N =100005, mod=1e9+7;
vector<ll>parent(N),sz(N);

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]); // Path compression
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        sz[b]=0;
    }
}



void solve() {
    // ll in, n, m, i, j, k, x, y;
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        parent[i]=i;
        sz[i]=1;
    }
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        x--; y--;
        union_sets(x,y);
    }
    ll ans=1;
    for(int i=0;i<n;i++){
        if(sz[i]>0) ans*=sz[i];
        ans%=mod;
    }
    cout<<ans<<endl;
    
}

int main() {
    int T=1;
    // cin>>T;
    for(int t=1;t<=T;t++) {
        solve();
    }
    return 0;
}
