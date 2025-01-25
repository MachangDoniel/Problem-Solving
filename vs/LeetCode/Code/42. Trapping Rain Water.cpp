class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,n=height.size();
        vector<int>premx(n);
        premx[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            premx[i]=max(premx[i+1],height[i]);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            int h=min(mx,premx[i]);
            ans+=(h-min(h,height[i]));
            mx=max(mx,height[i]);
        }
        return ans;
    }
};