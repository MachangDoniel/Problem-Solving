#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set= tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;  //ordered_set
 
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
 
// Const
const ll mod=1000000007;
const ll N=200005;
 
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

ll k;

class stack{
    public:
    vll s,smin={LLONG_MAX},smax={LLONG_MIN};
    void push(ll x){
        // cout<<"Push: "<<x<<" "<<::min(smin.back(),x)<<" "<<::max(smax.back(),x)<<endl;
        s.pb(x);
        smin.pb(::min(smin.back(),x));
        smax.pb(::max(smax.back(),x));
    }
    ll top(){
        // cout<<"Top: "<<s.back()<<endl;
        return s.back();
    }
    void pop(){
        // cout<<"Pop: "<<endl;
        s.pp();
        smin.pp();
        smax.pp();
    }
    bool empty(){
        // cout<<"Empty: "<<endl;
        return s.empty();
    }
    ll min(){
        // cout<<"min: "<<smin.back()<<endl;
        return smin.back();

    }
    ll max(){
        // cout<<"max: "<<smax.back()<<endl;
        return smax.back();
    }
};
::stack s1,s2;
void add(ll x){
    // cout<<"add: "<<endl;
    s2.push(x);
}
void remove(){
    // cout<<"remove: "<<endl;
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    s1.pop();
}
bool good(){
    // cout<<"good: "<<endl;
    ll mn=min(s1.min(),s2.min());
    ll mx=max(s1.max(),s2.max());
    return (mx-mn)<=k;
}

int main()
{
    Good_Luck;
    ll T=1;
    // cin>>T;
    //for(ll t=1;t<=T;t++){
    while(T--){
        ll in,n,m,i,j,x,y;
        cin>>n>>k;
        vll v(n);
        for(i=0;i<n;i++) cin>>v[i];
        ll sum=0,res=0;
        for(int l=0,r=0;r<n;r++){
            add(v[r]);
            while(!good()){
                remove();
                l++;
            }
            res+=(r-l+1);
            // cout<<r<<" "<<l<<" "<<(r-l+1)<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}