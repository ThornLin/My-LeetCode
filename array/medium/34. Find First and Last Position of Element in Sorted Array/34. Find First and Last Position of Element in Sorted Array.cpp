/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){return {-1, -1};}
        if(nums.size()==1 and nums[0]==target){return {0, 0};}
        
        int l=0, r=nums.size()-1, m=0;
        vector<int> v;
        
        while(l<r){
            m=(l+r)/2;
            if(nums[m]==target){break;}
            if(nums[l]==target){
                m=l;
                break;
            }
            if(nums[r]==target){
                m=r;
                break;
            }
            if(nums[l]<target and target<nums[m]){r=m-1;}
            else{l=m+1;}
        }
        if(nums[m]!=target){m=-1;}
        if(m>=0){
            l=m;
            r=m;
            while(l-1>=0 and nums[l-1]==target){l--;}
            while(r+1<=nums.size()-1 and nums[r+1]==target){r++;}
            v.push_back(l);
            v.push_back(r);
        }else{
            v.push_back(m);
            v.push_back(m);
        }
        return v;
    }
};*/

/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin=-1, end=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){begin=i; break;}
        }
        if(begin==-1){return {begin, end};}
        end=begin;
        while(end<nums.size() and nums[end]==target){end++;}
        return {begin, end-1};
    }
};*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int first = -1;
        int second = -1;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                if(first==-1)
                {
                    first = i;
                    second = i;
                }
                else
                    second = i;
            }
        }
        
        return {first,second};
    }
    
};
