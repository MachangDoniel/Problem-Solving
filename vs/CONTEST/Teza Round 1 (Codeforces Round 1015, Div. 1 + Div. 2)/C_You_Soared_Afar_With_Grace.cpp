#include<bits/stdc++.h>
using namespace std;

// #Define
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long


// Debugging
// #define LOCAL
// #include "debug.h"
#define dbg(x)


// MyTask

void solve(int &t,int &T){
    // ll in,n,m,i,j,k,x,y;
    int n; cin>>n;
    vector<int>a(n+1),b(n+1);
    map<pair<int,int>,int>pos;
    map<int,pair<int,int>>rev;
    int eq=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(a[i]==b[i]) eq++;
        pos[{a[i],b[i]}]=i;
        rev[i]={a[i],b[i]};
    }
    if(n%2==0){
        if(eq!=0){
            cout<<-1<<endl;
            return;
        }
    }
    else{
        if(eq!=1){
            cout<<-1<<endl;
            return;
        }
    }
    vector<pair<int,int>>move;
        
    for(int i=1;i<=n;i++){
        // a[i],b[i] already exists, check the reverse
        if((pos.find({b[i],a[i]})==pos.end())){
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=1;i<=n/2;i++){
        // pos of {a[i],b[i]} is at i
        int index=n+1-i;
        int idx=pos[{b[i],a[i]}];
        if(a[i]==b[i]){
            index=(n+1)/2;
        }
        // pos of {b[i],a[i]} must be at index
        if(index!=idx){
            move.push_back({idx,index});
            int f=rev[index].first;
            int s=rev[index].second;
            pos[{f,s}]=idx;
            rev[idx]={f,s};
            pos[{b[i],a[i]}]=index;
            rev[index]={b[i],a[i]};
            swap(a[idx],a[index]);
            swap(b[idx],b[index]);
        }
    }
    cout<<move.size()<<endl;
    for(auto it:move){
        cout<<it.first<<" "<<it.second<<endl;
    }
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=n;i>0;i--) cout<<b[i]<<" ";
    // cout<<endl;
}

int32_t main()
{
    Good_Luck;
    int T=1; 
    cin>>T;
    for(int t=1;t<=T;t++){
        solve(t,T);
    }
    return 0;
}

