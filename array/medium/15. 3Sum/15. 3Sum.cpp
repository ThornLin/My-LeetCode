/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution { // two pointer
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n ;i++){
            if(i>0 and nums[i]==nums[i-1]){continue;}
            int j=i+1, k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    v.push_back({nums[i], nums[j], nums[k]});
                    while(j<k and nums[j]==nums[j+1]){j++;}
                    while(j<k and nums[k]==nums[k-1]){k--;}
                    j++;
                    k--;
                }
                else if(sum>0){k--;}
                else{j++;}
            }          
        }
        return v;
    }
};
