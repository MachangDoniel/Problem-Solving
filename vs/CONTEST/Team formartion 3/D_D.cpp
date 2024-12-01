#include<bits/stdc++.h>
using namespace std;
//  Define

#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define pp pop_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound

// MyTask


int N=2000000+5;

void solve(){
    // ll in,n,m,i,j,k,x,y;
    int n,k; cin>>n>>k;
    vector<int> team,mp(N);
    for(int i=0;i<k;i++){
        int in; cin>>in;
        team.push_back(in);
        mp[in]++;
    }
    
    for(int i=1;i<=n;i++){
        if(mp[i-1]==0 && mp[i]==0 && mp[i+1]==0) team.pb(i),mp[i]++;
    }
    cout<<team.size()<<endl;
    // sort(team.begin(),team.end());
//     for(int i=0;i<team.size();i++){
//         cout<<team[i]<<" ";
//     }
//     cout<<endl;
}

int main()
{
    Good_Luck;
    int T=1; 
    // cin>>T;
    for(int t=1;t<=T;t++){
        solve();
    }
    return 0;
}