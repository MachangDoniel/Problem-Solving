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
#define defect cout<<"defect\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define extra(n) fixed<<setprecision(n)
#define space(n) right<<setfill(' ')<<setw(n)
#define vll vector<ll>
#define pll pair<ll,ll>
#define mpl map<ll,ll>
#define stl stack<ll>
#define dql deque<ll>
#define sl set<ll>
#define msl multiset<ll>
#define For(i,n) for(ll i=0;i<n;i++)
#define endl "\n"
#define io_from_file freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);

// Const
const ld PI = acos(-1.0);
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

ll n;
vector<pair<pll,ll>>processes;
vll gann_chart;

void fileIO(){
    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
}
void printV(){
    cout<<"Gann_Chart:  ";
    for(ll i=0;i<gann_chart.size();i++){
        cout<<space(1)<<"P"<<gann_chart[i]<<" ";
    }
    cout<<endl;
    cout<<"Time      :";
    for(ll i=0;i<=gann_chart.size();i++){
        cout<<space(2)<<i<<" ";
    }
    cout<<endl;
}
void utilization(){
    ll total_burst_time=0;
    for(ll i=0;i<processes.size();i++){
        total_burst_time+=processes[i].first.second;
    }
    cout<<"Utilization: "<<total_burst_time<<"/"<<gann_chart.size()<<"= "<<double(total_burst_time)/double(gann_chart.size())<<endl;
}
void throughput(){
    cout<<"Throughput: "<<processes.size()<<"/"<<gann_chart.size()<<"= "<<double(processes.size())/double(gann_chart.size())<<endl;
}

void print(){
    printV();
    utilization();
    throughput();
    // turned_around_time();
    // waiting_time();
    // response_time();
}

int main() {
    // fileIO();

    // printf("Enter the no of processes\n");
    cin>>n;
    // printf("Enter arrival time & burst time\n");
    // process[].first.first->arrival_time,process[].first.second->burst_time,process[].second->process_id
    vector<pair<pll,ll>>process;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        process.pb({{x,y},i+1});
    }
    processes=process;
    sort(all(process));
    ll completed=0,shortest_remaining_time,target_process_index;
    // for(ll i=0;i<n;i++){
    //     cout<<process[i].first.first<<" "<<process[i].first.second<<" "<<process[i].second<<endl;
    // }
    for(ll time=0;completed<n;time++){
        shortest_remaining_time=INT_MAX;
        target_process_index=-1;
        for(ll p=0;p<n;p++){
            if(process[p].first.first<=time && process[p].first.second>0 && process[p].first.second<shortest_remaining_time){
                target_process_index=p;
                shortest_remaining_time=process[p].first.second;
            }
        }
        if(target_process_index==-1) gann_chart.pb(-1);
        else{
            gann_chart.pb(process[target_process_index].second);
            process[target_process_index].first.second--;
            process[target_process_index].first.second?completed+=0:completed++;
        }
    }
    print();
    return 0;
}
