class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int mx=0,ans=0;
            for(int i=prices.size()-1;i>=0;i--){
                mx=max(prices[i],mx);
                ans=max(ans,mx-prices[i]);
            }
            return ans;
        }
    };