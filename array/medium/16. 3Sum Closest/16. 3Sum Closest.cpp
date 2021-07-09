/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_closer=100000, n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum==target){return sum;}
                if(abs(sum-target)<abs(min_closer-target)){
                    min_closer = sum;
                }
                else if(sum > target){r--;}
                else{l++;}
            }
        }
        return min_closer;
    }
};
