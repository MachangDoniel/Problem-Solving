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
const int MAXN = 100005;
const int LOG = 17;

vector<int> treeArr[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int v,int parent) {
    up[v][0] = parent;
    for (int j = 1; j < LOG; j++) {
        if (up[v][j - 1] != -1) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        } else {
            up[v][j] = -1;
        }
    }
    for (int u : treeArr[v]) {
        if (u != parent) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int lca(int u,int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = 0; j < LOG; j++) {
        if ((diff >> j) & 1) {
            u = up[u][j];
        }
    }
    if (u == v) return u;
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int distance(int u,int v) {
    int ancestor = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ancestor];
}

int find_middle(int u,int v) {
    int dist = distance(u, v);
    int ancestor = lca(u, v);
    int mid = dist / 2;

    if (depth[u] - depth[ancestor] >= mid) {
        for (int j = 0; j < LOG; j++) {
            if ((mid >> j) & 1) {
                u = up[u][j];
            }
        }
        return u;
    } else {
        int remaining_steps = dist - mid;
        for (int j = 0; j < LOG; j++) {
            if ((remaining_steps >> j) & 1) {
                v = up[v][j];
            }
        }
        return v;
    }
}

void solve() {
    int N, Q; 
    cin >> N;

    for (int i = 1; i <= N; i++) {
        treeArr[i].clear();
    }

    for (int i=1;i<N;i++) {
        int u, v;
        cin >> u >> v;
        treeArr[u].push_back(v);
        treeArr[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, -1);

    cin >> Q; 
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << find_middle(u, v) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
