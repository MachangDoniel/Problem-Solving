#include<bits/stdc++.h>
using namespace std;

// #Define
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    
// MyTask

void solve(){
    // ll in,n,m,i,j,k,x,y;
    int n; cin>>n;
    string s; cin>>s;
    map<char,int>mp;
    int current='#';
    for(int i=0;i<n;i++){
        if(s[i]!=current) mp[s[i]]++;
        current=s[i];
    }
    cout<<min(mp['0'],mp['1'])<<endl;
}

main()
{
    Good_Luck;
    int T=1; 
    cin>>T;
    for(int t=1;t<=T;t++){
        solve();
    }
}