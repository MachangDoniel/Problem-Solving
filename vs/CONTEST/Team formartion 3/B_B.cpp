#include<bits/stdc++.h>

using namespace std;
// Define
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// MyTask

void solve(){
    // ll in,n,m,i,j,k,x,y;
    int n; cin>>n;
    vector<int> v(n);
    int sum=0,littlesum=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        int num=v[i]%3;
        littlesum+=num;
        mp[num]++;
    }
    int remain=littlesum%3;
    sort(v.begin(),v.end());
    if(remain==1){
        int sum2=0,sum3=0;
        if(mp[1]>=1){
            sum2=sum;
            for(int i=0;i<n;i++){
                if(v[i]%3==1){
                    sum2-=v[i];
                    break;
                }
            }
        }
        if(mp[2]>=2){
            int count=0;
            sum3=sum;
            for(int i=0;i<n;i++){
                if(v[i]%3==2){
                    sum3-=v[i];
                    count++;
                    if(count==2) break;
                }
            }
        }
        sum=max(sum2,sum3);
    }
    else if(remain==2){
        int sum2=0,sum3=0;
        if(mp[1]>=2){
            int count=0;
            sum2=sum;
            for(int i=0;i<n;i++){
                if(v[i]%3==1){
                    sum2-=v[i];
                    count++;
                    if(count==2) break;
                }
            }
        }
        if(mp[2]>=1){
            sum3=sum;
            for(int i=0;i<n;i++){
                if(v[i]%3==2){
                    sum3-=v[i];
                    break;
                }
            }
        }
        sum=max(sum2,sum3);
    }
    cout<<sum<<endl;
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