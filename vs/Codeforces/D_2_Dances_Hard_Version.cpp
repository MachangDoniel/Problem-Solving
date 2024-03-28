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
#define int long long
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
#define mem(v,flag) memset(v, flag, sizeof(v))
 
// Const
const ll mod=1000000007;
const ll N=200005;
const ll inf=LLONG_MAX;
const ll minf=LLONG_MIN;

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
void primeFactors(int n){ 
    while(n%2==0){ 
        cout<<2<<" ", n=n/2; 
    } 
    for(int i=3;i*i<=n;i=i+2){ 
        while(n%i==0){ 
            cout<<i<<" ", n=n/i; 
        } 
    }
    if(n>2) cout<<n<<" "; 
} 
void printV(vector<int>v){
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
}
class DisjointSet {
    private:
        int parent[N];
        int size[N];
    public:
        DisjointSet() {
            for(int i=0;i<N;i++) {
                parent[i]=i;
                size[i]=1;
            }
        }
        void make_set(int v) {
            parent[v]=v;
            size[v]=1;
        }
        int find_set(int v) {
            if(v==parent[v]) return v;
            return parent[v]=find_set(parent[v]); // Path compression
        }
        void union_sets(int a,int b) {
            a=find_set(a);
            b=find_set(b);
            if(a!=b) {
                // Union by size
                if(size[a]<size[b]) swap(a,b);
                parent[b]=a;
                size[a]+=size[b];
            }
        }
    };

// MyTask

int find(vector<int> a,vector<int> b,int n,int num){
    a[n-1]=num; //initial step
    sort(all(a));
    int index=0;
    
    sort(all(b));
    // printV(a);
    // printV(b);
    for(int i=0;i<n;i++){
        if(b[i]>a[index]) index++;
    }
    return n-index;
}


main()
{
    Good_Luck;
    int T=1; 
    cin>>T;
    for(int t=1;t<=T;t++){
        // ll in,n,m,i,j,k,x,y;
        int n,m; cin>>n>>m;
        vector<int>a(n),b(n);
        for(int i=0;i<n-1;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int initial_step=find(a,b,n,1); //initial step
        int final_step=find(a,b,n,m); // final step
        // for(int i=1;i<=m;i++){
        //     cout<<i<<": "<<find(a,b,n,i)<<endl;
        // }
        if(initial_step==final_step){
            cout<<initial_step*m<<endl;
        }
        else{
            int high=m+1,low=-1;
            while(high>low+1){
                int mid=(high+low)/2;
                if(find(a,b,n,mid)==final_step) high=mid;
                else low=mid;
            }
            // cout<<high<<endl;
            cout<<initial_step*(high-1)+final_step*(m-high+1)<<endl;
        }
    }
}