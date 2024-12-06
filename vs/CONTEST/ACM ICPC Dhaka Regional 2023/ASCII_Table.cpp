#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
void solve(int &t,int &T) {
    char ch1,ch2; cin>>ch1>>ch2;
    int x=ch1,y=ch2;
    // cout<<x<<" "<<y<<endl;
    cout<<"Case "<<t<<":"<<endl;
    for(int i=1;i<=94;i++){
        if(x%i==y%i){
            cout<<i<<" ";
            int j=94/i;
            if(94%i) j++;
            cout<<j<<endl;
        }
    }
    cout<<endl;
}

main() {
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++){
        solve(t,T);
    }
    return 0;
}
