#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
# include <map>
using namespace std;
// #Define
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


// MyTask

void solve(int &t,int &T){
    // ll in,n,m,i,j,k,x,y;
    long long n; cin>>n;
    vector<long long>v(n),point(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    map<long long,long long>mp;
    long long count=0;
    for(long long i=n-1;i>=0;i--){
        if(v[i]==0) point[i]=count-mp[v[i]];
        else point[i]=count-mp[v[i]]-mp[-v[i]];
        mp[v[i]]++;
        count++;
    }
    // for(int i=0;i<n;i++){
    //     cout<<point[i]<<" ";
    // }
    // cout<<endl;
    
    long long sum=0;
    for(long long i=n-1;i>=0;i--){
        mp[v[i]]--;
        sum+=point[i]*(mp[-v[i]]);
        // cout<<sum<<" "<<mp[-v[i]]<<" "<<v[i]<<endl;
    }
    cout<<sum<<endl;
}

int main()
{
    Good_Luck;
    int T=1; 
    cin>>T;
    for(int t=1;t<=T;t++){
        solve(t,T);
    }
    return 0;
}