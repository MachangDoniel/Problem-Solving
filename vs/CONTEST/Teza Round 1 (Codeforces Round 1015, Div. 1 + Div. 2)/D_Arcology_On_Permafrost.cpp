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
    int n,m,k; cin>>n>>m>>k;
    vector<int>a;
    int num=0;
    while(a.size()<n){
        for(int i=0;i<m+1;i++){
            for(int j=0;j<k;j++){
                a.push_back(num+j);
                if(a.size()>=n){
                    for(int ele:a){
                        cout<<ele<<" ";
                    }
                    cout<<endl;
                    return;
                }
            }
        }
        num+=k;
    }
    for(int ele:a){
        cout<<ele<<" ";
    }
    cout<<endl;
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

