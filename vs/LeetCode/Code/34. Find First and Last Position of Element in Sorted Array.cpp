class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            auto good = [&](int mid,int target)->bool{
                return nums[mid]>=target;
            };
            auto bin_search = [&](int target)->int{
                int high=nums.size(),low=-1;
                while(high>low+1){
                    int mid=low+(high-low)/2;
                    if(good(mid,target)) high=mid;
                    else low=mid;
                }
                return high;
            };
            int start=bin_search(target);
            int end=bin_search(target+1)-1;
            if(0<=start && end<nums.size() && start<=end && nums[start]==target && nums[end]==target) return {start,end};
            return {-1,-1};
        }
    };