#include<bits/stdc++.h>
using namespace std;

// #Define
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    
// MyTask

void solve(){
    // your code goes here
    int a,b,k; cin>>a>>b>>k;
    // lets try b->a
    int ans=0;
    while(b!=a){
        if(b%k) ans+=b%k,b-=b%k;
        else if(b%k==0 && b/k>=a) ans++,b/=k;
        else if(b%k==0 && b/k<a) ans+=(b-a),b=a;
    }
    cout<<ans<<endl;
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
	