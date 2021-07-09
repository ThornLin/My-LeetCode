/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

/*
STEP 1: starting from the last, find the number which is less than its adjacent right, e.g in 5, 4, 7, 5, 3, 2, it is 4 at index 1(which also means that, from index 2, the numbers are sorted in descending order)
STEP 2: Now find the next greater number of 4 in it's rightpart(in this case it's 5).
STEP 3: swap them
STEP 4: we know that the numbers from the index of 4 is already in descending order.
so just reverse them, and this is the final answer
*/

/*class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                int j=i;
                while(j<nums.size() and nums[j]>nums[i-1]){j++;}
                j--;
                int tmp = nums[i-1];
                nums[i-1] = nums[j];
                nums[j] = tmp;
                
                sort(nums.begin()+i, nums.end());
                return ;
            }
        }
        sort(nums.begin(), nums.end());
        return ;
    }
};*/

/*class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0 and nums[i-1]>=nums[i]){i--;}
        if(i){
            int j=i;
            while(j<nums.size() and nums[j]>nums[i-1]){j++;}
            j--;
            
            int tmp = nums[i-1];
            nums[i-1] = nums[j];
            nums[j] = tmp;
            sort(nums.begin()+i, nums.end());
            return ;
        }
        sort(nums.begin(), nums.end());
        return ;
    }
};
