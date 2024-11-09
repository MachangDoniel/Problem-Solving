#include<bits/stdc++.h>
using namespace std;

// #Define
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

// MyTask

void solve(int &t,int &T){
    // ll in,n,m,i,j,k,x,y;
    int n; cin>>n;
    vector<int>scores(n);
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=0;j<8;j++) {
            int mark; cin>>mark; 
            sum+=mark; 
        }
        scores[i]=sum; 
    }
    for (int i=0;i<scores.size();i++) {
        cout<<scores[i]<<endl;
    }
    
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