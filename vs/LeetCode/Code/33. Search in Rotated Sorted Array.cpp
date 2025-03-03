class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n=nums.size();
            int initial_target=nums[n-1];
            int high=n,low=-1;
            auto good = [&](int mid)->bool{
                return nums[mid]<=initial_target;
            };
            while(high>low+1){
                int mid=low+(high-low)/2;
                if(good(mid)) high=mid;
                else low=mid;
            }
            auto binary_search=[&](int low,int high){
                while(high>=low){
                    int mid=low+(high-low)/2;
                    if(nums[mid]==target) return mid;
                    else if(nums[mid]<target) low=mid+1;
                    else high=mid-1;
                }
                return -1;
            };
            int ans=-1;
            if(high>0){
                // rotated
                // 0->high-1,high->n-1
                if(nums[0]<=target && target<=nums[high-1]){
                    ans=binary_search(0,high-1);
                }
                else if(nums[high]<=target && target<=nums[n-1]){
                    ans=binary_search(high,n-1);
                }
                else{
                    ans=-1;
                }
            }
            else{
                // not rotated
                // 0->n-1
                ans=binary_search(0,n-1);
            }
            return ans;
        }
    };