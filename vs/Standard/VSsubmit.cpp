#include<bits/stdc++.h>
using namespace std;

// #Define


void fileIO(){
    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);
}


int main() {
     fileIO();

    // printf("Enter the no of processes\n");
    cin>>n;
    // printf("Enter arrival time & burst time\n");
    // process[].first.first->arrival_time,process[].first.second->burst_time,process[].second->process_id
    vector<pair<pll,ll>>process;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        process.pb({{x,y},i+1});
    }
    processes=process;
    sort(all(process));
    ll completed=0,shortest_remaining_time,target_process_index;
    // for(ll i=0;i<n;i++){
    //     cout<<process[i].first.first<<" "<<process[i].first.second<<" "<<process[i].second<<endl;
    // }
    for(ll time=0;completed<n;time++){
        shortest_remaining_time=INT_MAX;
        target_process_index=-1;
        for(ll p=0;p<n;p++){
            if(process[p].first.first<=time && process[p].first.second>0 && process[p].first.second<shortest_remaining_time){
                target_process_index=p;
                shortest_remaining_time=process[p].first.second;
            }
        }
        if(target_process_index==-1) gann_chart.pb(-1);
        else{
            gann_chart.pb(process[target_process_index].second);
            process[target_process_index].first.second--;
            process[target_process_index].first.second?completed+=0:completed++;
        }
    }
    print();
    return 0;
}
