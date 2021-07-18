/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ?n / 2? times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int res=0, max_count=0;
        for(auto x: nums){
            m[x]++;
            if(m[x]>max_count){res=x; max_count=m[x];}
        }
        return res;
    }
};*/

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x: nums){
            m[x]++;
            if(m[x]>nums.size()/2){return x;}
        }
        return -1;
    }
};
