/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int res=1, n=nums.size(), max_jump=nums[0], jump=nums[0];
        for(int i=1; i<=min(max_jump, n-1); i++){
            max_jump=max(max_jump, i+nums[i]);
            if(i==n-1){return res;}
            if(i==jump){jump=max_jump; res++;}
        }
        return 0;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0, max_val=0, end=0;
        for(int i=0; i<nums.size()-1; i++){
            max_val=max(max_val, i+nums[i]);
            if(i==end){
                end=max_val;
                res++;
            }
        }
        return res;
    }
};
