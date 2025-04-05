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
    if(n%2){
        cout<<n<<" ";
        for(int i=1;i<n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
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

