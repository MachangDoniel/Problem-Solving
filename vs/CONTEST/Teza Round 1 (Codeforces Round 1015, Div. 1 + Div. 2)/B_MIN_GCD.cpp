#include<bits/stdc++.h>
using namespace std;

// #Define
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

int gcd(int a, int b) {if (b==0) return a; return gcd(b,a%b);} //__gcd

// Debugging
// #define LOCAL
// #include "debug.h"
#define dbg(x)


// MyTask

void solve(int &t,int &T){
    // ll in,n,m,i,j,k,x,y;
    int n; cin>>n;
    vector<int>v(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    bool flag=false;
    vector<int>div;
    for(int i=1;i<n;i++){
        if(v[i]%v[0]==0){
            div.push_back(v[i]/v[0]);
        }
    }
    if(div.empty()){
        cout<<"No"<<endl;
        return;
    }
    int g=div[0];
    for(int i=0;i<div.size();i++){
        g=gcd(g,div[i]);
    }
    g==1?cout<<"Yes"<<endl:cout<<"No"<<endl;
    
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

