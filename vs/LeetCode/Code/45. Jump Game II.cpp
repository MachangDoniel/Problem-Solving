class Solution {
public:
    int jump(vector<int>& nums) {
        int max_jump=nums.size();
        vector<int>jump(nums.size(),max_jump);
        jump[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<min(max_jump,i+1+nums[i]);j++){
                jump[j]=min(jump[j],jump[i]+1);
                if(j==max_jump-1){
                    return jump[nums.size()-1];
                }
            }
        }
        return jump[nums.size()-1];
    }
};