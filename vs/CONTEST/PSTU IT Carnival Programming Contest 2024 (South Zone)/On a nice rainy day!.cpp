#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


// define
# define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

const int mod=10000007;

int bigmod(int a,int p,int m){
    if(p==0) return 0;
    int q=bigmod(a,p/2,m);
    if(p%2==0) return (q*q)%m;
    return (q*(q*a)%m)%m;
}

// nCr
//vector<vector<int>>dp(1003,vector<int>(1003,0));
//int nCr(){
//    for(int i=0;i<1003;i++) dp[i][0]=1;
//    for(int i=1;i<1003;i++){
//        for(int j=1;j<1003;j++){
//            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
//        }
//    }
//}

void print(vector<int>&v){
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

void solve(int &t,int &T){
    int x,y; cin>>x>>y;
    cout<<-x<<" "<<y<<endl;
    cout<<x<<" "<<-y<<endl;
    cout<<-x<<" "<<-y<<endl;
}

main(){
    // cout<<"Hello World"<<endl;
    Good_Luck;
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        solve(t,T);
    }
}