/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]
*/

/*class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> smallerNumbers;
        int count;
        for(int i=0; i<nums.size(); i++){
            count = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i]>nums[j])
                    count++;
            }
            smallerNumbers.push_back(count);
        }
        return smallerNumbers;
    }
};*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int ary[101] = {0};
        for(int i=0; i<nums.size(); i++){ // count number of element in array
            ary[nums[i]]++;
        }
        for(int i=1; i<sizeof(ary)/sizeof(ary[0]); i++){ // count number of element smaller than now number
            ary[i] += ary[i-1];
        }
        for(int i=0; i<nums.size(); i++){
            if(!nums[i]) nums[i]=0;
            else nums[i] = ary[nums[i]-1];
        }
        return nums;
    }
};
