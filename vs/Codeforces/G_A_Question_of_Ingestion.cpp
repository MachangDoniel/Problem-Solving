#include <bits/stdc++.h>
using namespace std;

#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
void solve() {
    int n,m; cin>>n>>m; 
    vector<int> calories(n);
    for (int i=0;i<n;i++) {
        cin>>calories[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));   //maximum calories up to hour i, eaten in j hours
    vector<double> eatableCalories(n+1);
    eatableCalories[0]=m*1.0; 
    for(int i=1;i<=n;i++){
        eatableCalories[i]=(eatableCalories[i-1]*2.0)/3.0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][0]=max(dp[i][0],dp[i-1][j]); 
            if (j>0){
                int caloriesEaten=min(calories[i-1],static_cast<int>(eatableCalories[j-1]));
                dp[i][j]=dp[i-1][j-1]+caloriesEaten; // Eat in this hour
            }
        }
    }

    int result=0;
    for(int j=0;j<=n;j++) {
        result=max(result,dp[n][j]);
    }
    cout<<result<<endl;
}

main() {
    Good_Luck;
    solve();
    return 0;
}
