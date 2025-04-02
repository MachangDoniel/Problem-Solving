class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int count=0;
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++){
                if(val!=nums[i]){
                    nums[count++]=nums[i];
                }
            }
            return count;
        }
    };