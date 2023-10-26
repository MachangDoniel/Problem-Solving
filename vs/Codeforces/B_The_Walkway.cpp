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

// MyTask

int counter(int d,vector<int>s){    // to count the no of cookies petya will eat during the walkaway
    int ans=0;
    for(int i=1;i<s.size();i++){
        ans+=(s[i]-s[i-1]-1)/d;     // find the no of cookies petya will eat between 2 sellers
    }
    ans+=s.size()-2;                // for the virtual (first and last) sellers that we added extra, we need to remove them
    return ans;
}

int main()
{
    Good_Luck;
    int T=1;
    cin>>T;
    //for(ll t=1;t<=T;t++){
    while(T--){
        int in,n,m,i,j,k,x,y;
        int d;
        cin>>n>>m>>d;
        vector<int> s(m);
        for(i=0;i<m;i++){
            cin>>s[i];
        }
        s.insert(s.begin(),1-d);    // added an extra seller to make compatible with the formula to count the no of cookies petya will eat before the 1st seller 
        s.pb(n+1);                  // added an extra seller to make compatible with the formula to count the no of cookies petya will eat after the last seller 
        int ans=2e9;
        vector<int>cookiesseller;
        for(i=1;i<=m;i++){
            int cookiessaving=(s[i+1]-s[i-1]-1)/d-(1+(s[i]-s[i-1]-1)/d+(s[i+1]-s[i]-1)/d);
            // cout<<": "<<s[i-1]<<" "<<s[i]<<" "<<s[i+1]<<endl;
            if(cookiessaving<ans){   //find min cookiessaving to count removing of how many cookies seller cookiessellerults the min cookiessaving
                ans=cookiessaving;
                cookiesseller.clear();
                // cout<<"<  "<<endl;
            }
            if(cookiessaving==ans){
                cookiesseller.pb(s[i]);
                // cout<<"==  "<<endl;
            }
            // cout<<i<<": "<<cookiessaving<<" "<<ans<<" "<<cookiesseller.size()<<endl;
        }
        cout<<ans+counter(d,s)<<" "<<cookiesseller.size()<<endl;

    }
    return 0;
}