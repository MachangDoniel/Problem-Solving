#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set= tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;  //ordered_set
template <typename T>
using multi_ordered_set= tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;  //multiple_ordered_set
 
// #Define
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define pp pop_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define MP make_pair
#define YES cout<<"YES\n"
#define NO  cout<<"NO\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define extra(n) fixed<<setprecision(n)
#define For(n) for(ll i=0;i<n;i++)
#define vll vector<ll>
#define pll pair<ll,ll>
#define mpl map<ll,ll>
#define umpl unordered_map<ll,ll>
#define lll list<ll>
#define stl stack<ll>
#define qll queue<ll>
#define pql priority_queue<ll>
#define sll set<ll>
#define msl multiset<ll>
#define osl ordered_set<ll>
#define mosl multi_ordered_set<ll>
 
// Const
const ll mod=1000000007;
const ll N=200005;
const ll inf=2e18;

// Mathematical functions
ll gcd(ll a, ll b) {if (b==0) return a; return gcd(b,a%b);} //__gcd
ll lcm(ll a, ll b) {return (a/gcd(a,b) * b);}
ll power(ll x, ll y) { ll a=1;for(ll i=0;i<y;i++) a*= x;return a;}
ll square_root(ll x) {
    ll low=1,high=3e9,ans=1; while(low<=high) {
        ll mid = (low + high)/2;
        if (mid*mid<=x){ans=mid;low=mid+1;} else high=mid-1;
    } return ans;
}
bool isPrime(ll n){
    if (n<=1)return false; if(n<=3)return true; if(n%2==0 || n%3==0) return false;
    for (ll i=5;i*i<=n;i=i+6) if(n%i==0 || n%(i+2)==0) return false;
    return true;
}
ll factorial(ll n){
    if(n<0) return -1;
    else if(n==0) return 1;
    else return n*factorial(n-1);
}
ll permutation(ll n, ll r) {
    if (n < r) return -1;
    return factorial(n)/factorial(n-r);
}
ll combination(ll n,ll r){
    if(n<r) return -1;
    else return factorial(n)/factorial(n-r)/factorial(r);
}

#define LOCAL
#include "debug.h"
// #define dbg(x)

// MyTask

void printV(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int findMex(vector<int>v,map<int,int>mp){
    sort(all(v));
    for(int i=0;i<v.size();i++){
        if(!mp[i]) return i;
    }
    return v.size();
}

int main()
{
    Good_Luck;
    int T=1;
    cin>>T;
    //for(ll t=1;t<=T;t++){
    while(T--){
        // ll in,n,m,i,j,k,x,y;
        int n;
        cin>>n;
        vector<int>v(n);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>v[i];
            mp[v[i]]++;
        }

        dbg(mp);

        int mex=findMex(v,mp);
        if(mex==n) NO;
        else{
            // cout<<mex<<endl;
            if(mp[mex+1]<=1) YES;
            else{
                int right=-2e9,left=2e9;
                for(int i=0;i<n;i++){
                    if(v[i]==mex+1){
                        left=min(left,i);
                        right=max(right,i);
                    }
                }
                map<int,int>mp2;
                vector<int>vv;
                for(int i=left+1;i<right;i++){
                    if(v[i]>=mex) continue;
                    if(!mp2[v[i]]) vv.pb(v[i]);
                    mp2[v[i]]++;
                }
                int count=0;
                // printV(vv);
                for(int i=0;i<vv.size();i++){
                    if(mp[vv[i]]==mp2[vv[i]]) count++;
                    // cout<<vv[i]<<" "<<mp[vv[i]]<<endl;
                }
                count<1?YES:NO;
            }
        }
    }
    return 0;
}