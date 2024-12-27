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


vector<long long> find_divisors(long long n){
    vector<ll> divisors;
    for (ll i=1;i*i<=n;i++){
        if (n%i==0){
            divisors.push_back(i);
            if (i!=n/i) divisors.push_back(n/i);
        }
    }
    return divisors;
}

ll numberOfCoprime(ll n){
    ll result=n;
    for (ll i=2;i*i<=n;i++){
        if (n%i==0) {
            while (n%i==0)
                n/=i;
            result-= result/i;
        }
    }
    if (n>1)
        result-=result/n;
    return result;
}

void solve(int t){
    ll n,q; cin>>n>>q;
    cout<<"Case "<<t<<": ";
    vector<ll>queries(q);
    for (int i=0;i<q;i++){
        cin>>queries[i];
    }
    vector<ll>divisors=find_divisors(n);
    sort(all(divisors));
    vector<ll> totient(divisors.size());
    for (int i=0;i<divisors.size();i++)
    {
        ll d=divisors[i];
        totient[i]=numberOfCoprime(n/d);
    }
    for(ll m: queries){
        if (n%m!=0) {
            cout<<0<<" ";
        }
        else{
            auto it = lower_bound(all(divisors),m);
            ll idx = it - divisors.begin();
            cout << totient[idx] << " ";
        }
    }
    cout<<endl;
}

int main() {
    Good_Luck;
    int T;
    cin >> T; // Number of test cases
    for(int t=1;t<=T;t++){
        solve(t);
    }
    return 0;
}
