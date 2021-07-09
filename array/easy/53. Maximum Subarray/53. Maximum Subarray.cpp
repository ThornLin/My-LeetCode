/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
*/

/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = -100000;
        for(int i=0; i<nums.size(); i++){
            int sub_sum = 0;
            for(int j=i; j<nums.size(); j++){
                sub_sum += nums[j];
                max_sum = max(max_sum, sub_sum);
            }
        }
        return max_sum;
    }
};*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sub_sum = nums[0], max_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            sub_sum = max(sub_sum+nums[i], nums[i]);
            max_sum = max(max_sum, sub_sum);
        }
        return max_sum;
    }
};
