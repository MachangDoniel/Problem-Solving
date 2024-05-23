#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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


int inf=1000000005;


// MLE
// void solve(){
//     // ll in,n,m,i,j,k,x,y;
//     int n; cin>>n;
//     vector<pair<int,int> >stops(n+2);
//     for(int i=1;i<=n;i++){
//         cin>>stops[i].first>>stops[i].second;
//     }
//     int dest,fuel; cin>>dest>>fuel;
//     stops[0].first=0;
//     stops[0].second=-inf;
//     stops[n+1].first=dest;
//     stops[n+1].second=0;
//     for(int i=1;i<=n;i++){
//         stops[i].first=dest-stops[i].first;
//     }

//     sort(stops.begin(),stops.end());
//     // for(int i=0;i<n+2;i++){
//     //     cout<<stops[i].first<<" "<<stops[i].second<<endl;
//     // }
//     // cout<<endl;
//     // starting at 0, destination at n+1
//     vector<pair<int,int> > dp,prev;       // {steps,fuel left}
//     bool possible=true;
//     int cur=0;
//     dp.pb({0,fuel});  // at starting point {0,starting fuel}
//     prev=dp;
//     for(int i=1;i<n+2;i++){
//         dp.clear();
//         int dis=stops[i].first-cur;
//         if(prev.size()==0){
//             possible=false;
//             break;
//         }
//         else{
//             for(int j=0;j<prev.size();j++){
//                 // cout<<"at "<<stops[i-1].first<<", steps: "<<prev[j].first<<" fuel: "<<prev[j].second<<", dis: "<<dis<<endl;
//                 if(prev[j].second>=dis){
//                     dp.pb({prev[j].first,prev[j].second-dis});
//                     // cout<<"1: "<<prev[j].first<<" "<<prev[j].second-dis<<endl;
//                 }
//                 if(prev[j].second>dest){
//                     break;
//                 }
//                 int fuel=prev[j].second-dis+stops[i-1].second;    // take fuel from previous to reach at current position
//                 if(fuel>=0){                                         // if taking from previous is enought to reacht at current postion, take it
//                     dp.pb({prev[j].first+1,fuel});
//                     // cout<<"2: "<<prev[j].first+1<<" "<<fuel<<endl;
//                 }
//             }
//             prev=dp;
//             cout<<endl;
//             cur=stops[i].first;
//             dp=prev;
//         }
//     }
//     if(possible){
//         int mn=inf;
//         for(int i=0;i<dp.size();i++){
//             mn=min(mn,dp[i].first);
//         }
//         cout<<mn<<endl;
//     }
//     else cout<<-1<<endl;
// }

void solve(){
    // ll in,n,m,i,j,k,x,y;
    int n; cin>>n;
    vector<pair<int,int> >stops(n+1);
    for(int i=0;i<n;i++){
        cin>>stops[i].first>>stops[i].second;
    }
    int dest,fuel; cin>>dest>>fuel;
    stops[n].first=dest;
    stops[n].second=0;
    for(int i=0;i<n;i++){
        stops[i].first=dest-stops[i].first;
    }
    sort(stops.begin(),stops.end());
    // for(int i=0;i<n+1;i++){
    //     cout<<stops[i].first<<" "<<stops[i].second<<endl;
    // }
    // cout<<endl;
    // starting at 0, destination at n+1
    bool possible=true;
    priority_queue<int>pq;
    int count=0;
    for(int i=0;i<n+1;i++){
        // cout<<stops[i].first<<"-> ";
        
        while(stops[i].first>fuel){
            if(pq.empty()){
                possible=false;
                break;
            }
            count++;
            // cout<<"take: "<<pq.top()<<endl;
            fuel+=pq.top();
            pq.pop();
        }
        pq.push(stops[i].second);
    }
    if(possible) cout<<count<<endl;
    else cout<<-1<<endl;

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