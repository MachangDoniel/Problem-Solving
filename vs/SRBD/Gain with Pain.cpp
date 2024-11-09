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

// GNU PBDS Headers
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Using standard and GNU PBDS namespaces
using namespace std;
using namespace __gnu_pbds;

// Defining ordered_set and multi_ordered_set templates
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Macros
#define Good_Luck ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define pp pop_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define MP make_pair
#define YES cout << "YES\n"
#define NO  cout << "NO\n"
#define emo cout << "('_')\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define extra(n) fixed << setprecision(n)
#define For(n) for (ll i = 0; i < n; i++)
#define endl "\n"
#define vll vector<long long>
#define pll pair<long long, long long>
#define mpl map<long long, long long>
#define umpl unordered_map<long long, long long>
#define lll list<long long>
#define stl stack<long long>
#define qll queue<long long>
#define pql priority_queue<long long>
#define sll set<long long>
#define msl multiset<long long>
#define osl ordered_set<long long>
#define mosl multi_ordered_set<long long>
#define mem(v, flag) memset(v, flag, sizeof(v))

// MyTask

void solve() {
    // ll in, n, m, i, j, k, x, y;
    int n,m,q,r; cin>>n;
    bool flag=true;
        
    for(int i=0;i<n;i++){
        // back
        cin>>m>>q>>r;
        if(!(m==2 and q==3 and r==10)) flag=false;
        // leg
        cin>>m>>q>>r;
        if(!(m==2 and q==3 and r==10)) flag=false;
        // chest
        cin>>m>>q>>r;
        if(!(m==2 and q==3 and r==10)) flag=false;
        // shoulder
        cin>>m>>q>>r;
        if(!(m==1 and q==3 and r==10)) flag=false;
        // arm
        cin>>m>>q>>r;
        if(!(m==3 and q==3 and r==10)) flag=false;
    }
    if(flag) cout<<"Consistent"<<endl;
    else cout<<"Inconsistent"<<endl;
}

int main() {
    Good_Luck;
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++) {
        solve();
    }
    return 0;
}
