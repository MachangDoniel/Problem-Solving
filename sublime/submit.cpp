#include<bits/stdc++.h>
using namespace std;
 
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
#define vll vector<ll>
#define pll pair<ll,ll>
#define mpl map<ll,ll>
#define umpl unordered_map<ll,ll>
#define sll set<ll>
#define lll list<ll>
#define stl stack<ll>
#define msl multiset<ll>
#define qll queue<ll>
#define pql priority_queue<ll>
#define For(n) for(ll i=0;i<n;i++)
#define endl "\n"
 
// Const
const ll mod=1000000007;
const ll inf=2e9;
const ll minf=-1e17;
const ll N=200005;
const ld eps=1e-8;
const ll ll_MAX=9223372036854775807;
 
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
 
ll combination(ll n,ll r){
    if(n<r) return -1;
    else return factorial(n)/factorial(n-r)/factorial(r);
}
 
// MyTask

void printL(lll li){
    for(auto it:li) cout<<it<<" ";
        cout<<endl;
}
 
int main()
{
    Good_Luck;
    ll T=1;
    // cin>>T;
    //for(ll t=1;t<=T;t++){
    while(T--){
        ll in,n,m,i,j,k,x,y;
        cin>>n;
        vll v(n);
        ll sum=0,mx=INT_MIN;
        for(i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
            mx=max(mx,v[i]);
        }
        cout<<max(2*mx,sum)<<endl;
    }
    return 0;
}