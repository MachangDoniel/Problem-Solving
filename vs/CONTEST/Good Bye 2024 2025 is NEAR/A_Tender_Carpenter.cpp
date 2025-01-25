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
#define eb emplace_back
#define pp pop_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define MP make_pair
#define YES cout<<"YES\n"
#define NO  cout<<"NO\n"
#define emo cout<<"('_')\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define extra(n) fixed<<setprecision(n)
#define For(n) for(int i=0;i<n;i++)
#define vll vector<int>
#define pll pair<int,int>
#define mpl map<int,int>
#define umpl unordered_map<int,int>
#define lll list<int>
#define stl stack<int>
#define qll queue<int>
#define pql priority_queue<int>
#define sll set<int>
#define msl multiset<int>
#define osl ordered_set<int>
#define mosl multi_ordered_set<int>
#define mem(v,flag) memset(v, flag, sizeof(v))
 
// Const
const int mod=1000000007;
const int N=200005;
const int inf=LLONG_MAX;
const int minf=LLONG_MIN;
const ld pi=2*acosl(0);

// Mathematical functions
int gcd(int a, int b) {if (b==0) return a; return gcd(b,a%b);} //__gcd
int lcm(int a, int b) {return (a/gcd(a,b) * b);}
int power(int x, int y) { int a=1;for(int i=0;i<y;i++) a*= x;return a;}
int square_root(int x) {
    int low=1,high=3e9,ans=1; while(low<=high) {
        int mid = (low + high)/2;
        if (mid*mid<=x){ans=mid;low=mid+1;} else high=mid-1;
    } return ans;
}

// Sorting
bool sorta(pll a,pll b){ return a.second<b.second;}
bool sortd(pll a,pll b){ return a.second>b.second;}

bool isPrime(int n){
    if (n<=1)return false; if(n<=3)return true; if(n%2==0 || n%3==0) return false;
    for (int i=5;i*i<=n;i=i+6) if(n%i==0 || n%(i+2)==0) return false;
    return true;
}
int bigMod(int a,int p,int m){
    if(p == 0) return 1;
    int q = bigMod(a, p/2, m);
    if(p % 2 == 0) return (q*q) % m;
    return (q*((q*a) % m)) % m;
}
int modInverse(int a, int m){
    int m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1){
        int q=a/m,t=m; // q is quotient
        m=a%m,a=t,t=y; // m is remainder now, process same as Euclid's algo
        y=x-q*y,x=t; // Update y and x
    }
    if(x<0) x+=m0;  // Make x positive
    return x;
}
vector<int>fact,invFact;
vector<vector<int>>comb;
void precomputeFactorials() {
    fact.resize(N);
    invFact.resize(N);
    fact[0]=1;
    for(int i=1;i<N;i++) {
        fact[i]=(fact[i-1]*i)%mod;
    }
    invFact[N-1]=bigMod(fact[N-1],mod-2,mod); // Fermat’s inverse for the last factorial
    for(int i=N-2;i>=0;i--) {
        invFact[i]=(invFact[i+1]*(i+1))%mod;
    }
}
int permutation(int n,int r) {
    if(n<r) return -1;
    return fact[n]/fact[n-r];
}
void combination() {
    comb.resize(N);
    for(int i=0;i<N;i++) {
        comb[i][0]=1;
        for(int j=1;j<=i;j++) {
            comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
        }
    }
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
struct SimpleHash {
    long long len, base, mod;
    vector<long long> P, H, R;
    SimpleHash() {}
    SimpleHash(string str, long long b, long long m) {
        base = b, mod = m, len = str.size();
        P.resize(len + 4, 1), H.resize(len + 3, 0), R.resize(len + 3, 0);
        for (long long i = 1; i <= len + 3; i++)
            P[i] = (P[i - 1] * base) % mod;
        for (long long i = 1; i <= len; i++)
            H[i] = (H[i - 1] * base + str[i - 1]+1007) % mod;
        for (long long i = len; i >= 1; i--)
            R[i] = (R[i + 1] * base + str[i - 1]+1007) % mod;
    }
    inline long long range_hash(long long l, long long r) {
        long long hashval = (H[r + 1] - (P[r - l + 1] * H[l] % mod))%mod;
        return (hashval < 0 ? hashval + mod : hashval);
    }
    inline long long reverse_hash(long long l, long long r) {
        long long hashval = R[l + 1] - (P[r - l + 1] * R[r + 2] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
};
struct DoubleHash {
    SimpleHash sh1, sh2;
    DoubleHash() {}
    DoubleHash(string str) {
        sh1 = SimpleHash(str, 1949313259, 2091573227);
        sh2 = SimpleHash(str, 1997293877, 2117566807);
    }
    long long concate(DoubleHash& B, long long l1 , long long r1 , long long l2 , long long r2) {
        long long len1 = r1 - l1+1 , len2 = r2 - l2+1;
        long long x1 = sh1.range_hash(l1, r1) ,
        x2 = B.sh1.range_hash(l2, r2);
        x1 = (x1 * B.sh1.P[len2]) % 2091573227;
        long long newx1 = (x1 + x2) % 2091573227;
        x1 = sh2.range_hash(l1, r1);
        x2 = B.sh2.range_hash(l2, r2);
        x1 = (x1 * B.sh2.P[len2]) % 2117566807;
        long long newx2 = (x1 + x2) % 2117566807;
        return (newx1 << 32) ^ newx2;
    }
    inline long long range_hash(long long l, long long r) {
        return (sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }
    inline long long reverse_hash(long long l, long long r) {
        return (sh1.reverse_hash(l, r) << 32) ^ sh2.reverse_hash(l, r);
    }
};
class DisjointSet {
    private:
        vector<int> parent,size;
    public:
        DisjointSet() {}
        DisjointSet(int n) { resize(n);}
        void resize(int n) {
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++) {
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
class SegmentTree{
    private:
        int n;
        vector<int>segmentTree,lazyTree;
    public:
        SegmentTree(){}
        SegmentTree(int n){ resize(n);}
        void resize(int n){
            this->n=n;
            segmentTree.resize(4*n,0);
            lazyTree.resize(4*n,0);
        }
        void push(int start,int ending,int node){
            if(lazyTree[node]){
                segmentTree[node]=max(lazyTree[node],segmentTree[node]);
                if (start!=ending){
                    lazyTree[2*node+1]=max(lazyTree[2*node+1],lazyTree[node]);
                    lazyTree[2*node+2]=max(lazyTree[2*node+2],lazyTree[node]);;
                }
                lazyTree[node]=0;
            }
        }
        int query(int start,int ending,int l,int r,int node){
            push(start,ending,node);
            if (start>r || ending<l) return 0;
            if (start>=l && ending<=r) return segmentTree[node];
            int mid=(start+ending)/2;
            int q1=query(start,mid,l,r,2*node+1);
            int q2=query(mid+1,ending,l,r,2*node+2);
            return max(q1,q2);
        }
        void update(int start,int ending,int node,int l,int r,int value){
            push(start,ending,node);
            if (start>r || ending<l) return;
            if (start>=l && ending<=r){
                lazyTree[node]=value;
                push(start,ending,node);   
                return;
            }
            // partial case
            int mid=(start+ending)/2;
            update(start,mid,2*node+1,l,r,value);
            update(mid+1,ending,2*node+2,l,r,value);
            segmentTree[node]=max(segmentTree[node*2+1],segmentTree[node*2+2]);
            return;
        }
        int query(int l,int r){ return query(0,n-1,l,r,0);}
        void update(int l,int r,int x){ update(0,n-1,0,l,r,x);}
};
void print(vector<int>v){
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
}
void print(set<int>s){
    for(auto it:s) cout<<it<<" ";
    cout<<endl;
}
void print(multiset<int>s){
    for(auto it:s) cout<<it<<" ";
    cout<<endl;
}
void print(map<int,int>mp){
    for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
}
void print(stack<int>st){
    while(!st.empty()) cout<<st.top()<<" ",st.pop();
    cout<<endl;
}
void print(queue<int>q){
    while(!q.empty()) cout<<q.front()<<" ",q.pop();
    cout<<endl;
}
int time_limit=1e9,time_count=0;
bool checkTime(){
    time_count++;
    if(time_count>time_limit){
        cout<<"Time Limit Apprehension (-_-)"<<endl;
        return false;
    }
    return true;
}
vll intToBin(int n){
    vll bin(32);
    for(int i=0;i<32;i++) bin[31-i]=n&1, n>>=1;
    // for(int i=0;i<32;i++) cout<<bin[i]<<" ";
    // cout<<endl;
    return bin;
}


// Debugging
// #define LOCAL
// #include "debug.h"
#define dbg(x)


// MyTask

void solve(int &t,int &T){
    // ll in,n,m,i,j,k,x,y;
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int mn=min(a[i-1],a[i]);
        int mx=max(a[i-1],a[i]);
        if(a[i-1]==a[i] || (mn<mx && 2*mn>mx)){
            YES;
            return;
        }
    }
    NO;
}

main()
{
    Good_Luck;
    int T=1; 
    cin>>T;
    for(int t=1;t<=T;t++){
        solve(t,T);
    }
}

