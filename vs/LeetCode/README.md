# LeetCode problem and solution
## [189. Rotate Array](https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150)
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

***Example 1:***

*Input:* nums = [1,2,3,4,5,6,7], k = 3
*Output:* [5,6,7,1,2,3,4]
**Explanation:**
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

***Example 2:***

*Input*: nums = [-1,-100,3,99], k = 2
*Output:* [3,99,-1,-100]
**Explanation: **
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
**Constraints:**
- `1 <= nums.length <= 105`
- `-231 <= nums[i] <= 231 - 1`
- `0 <= k <= 105`
 

*Follow up:*
- Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
- Could you do it in-place with O(1) extra space?

## Solution:
### Idea:
To rotate an array to the right by `k` steps:

- **Use Modulo to Handle Large k Values:**
When k is larger than the length of the array, rotating the array by `k` steps would just be the same as rotating it by `𝑘`%(array length) steps. This ensures we don't do unnecessary rotations and work with manageable values of 
`𝑘`.
- **Reverse the Entire Array:**
By reversing the entire array, we change the order of elements so that what was previously at the end moves to the beginning. This "prepares" the array for the next steps by moving elements towards their target positions.

- **Reverse the First k Elements:**
By reversing the first `𝑘` elements in the reversed array(last `n-k` elements in the actual array), we move them to their correct positions for the rotation.

- **Reverse the Remaining Elements:**
Lastly, reversing the remaining elements (from index 
`𝑘` to the end) puts the rest of the array in the right order.

### Why This Works

**Reversing the Entire Array:** moves all elements so that the last elements become the beginning, simulating a rightward shift.
**Reversing Subarrays:** by reversing the first `𝑘` elements and then the rest, we align the elements exactly where they would be after a rightward rotation of `𝑘` steps.

This method is efficient and meets the problem constraints for the following reasons:

- **In-Place with `𝑂(1)` Extra Space:**

    Unlike approaches that might require an additional array (which takes `𝑂(𝑛)` space), this solution only rearranges elements within the existing array.

- **Linear Time Complexity`𝑂(𝑛)`**

    The three reversals each take `𝑂(𝑛)` time. This is optimal for an in-place solution since we need to "touch" each element of the array to move it to its new position.

### [Code](./Code/189.%20Rotate%20Array.cpp)
```code
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        k%=(nums.size());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
```