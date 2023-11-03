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
#define endl "\n"
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
const ll N=200001;
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

// MyTask


int main()
{
    Good_Luck;
    int T=1;
    cin>>T;
    //for(ll t=1;t<=T;t++){
    while(T--){
        // ll in,n,m,i,j,k,x,y;
        int n,parent_of_source=-1;
        cin>>n;
        vector<int>first_access(n+1),ans(n+1),vis(n+1);
        map<pair<int,int>,int>pos;
        vector<int>adj_list[n+1];

        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            if(parent_of_source==-1 && (x==1 || y==1)) parent_of_source=i;
            adj_list[x].pb(y);
            adj_list[y].pb(x);
            pos[{min(x,y),max(x,y)}]=i;
        }

        //bfs part
        int source=1;
        queue<int>q;
        q.push(source);
        first_access[source]=parent_of_source;
        ans[source]=1;
        vis[source]=1;
        while(!q.empty()){
            int parent=q.front();
            q.pop();
            for(int child:adj_list[parent]){
                if(!vis[child]){
                    q.push(child);
                    first_access[child]=pos[{min(parent,child),max(parent,child)}];
                    if(first_access[parent]<=first_access[child]) ans[child]=ans[parent];
                    else ans[child]=ans[parent]+1;
                    vis[child]=1;
                }
            }
        }
        sort(all(ans));
        cout<<ans[n]<<endl;
    }
    return 0;
}