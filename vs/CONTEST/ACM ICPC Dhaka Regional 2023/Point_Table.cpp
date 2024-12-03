#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
void solve(int &t,int &T) {
    vector<int> a(3,0);
    for(int i=0;i<3;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<vector<int>>ans={{0,3,6},{0,4,4},{1,2,4},{1,1,6},{2,2,2},{3,3,3}};
    cout<<"Case "<<t<<": ";
    for(int i=0;i<6;i++){
        if(a==ans[i]){
            cout<<"perfectus"<<endl;
            return;
        }
    }
    cout<<"invalidum"<<endl;
}

main() {
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++){
        solve(t,T);
    }
    return 0;
}
