/*
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
*/

/*class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0, n=digits.size()-1;
        digits[n] += 1;
        for(int i=n; i>=0; i--){
            digits[i] += carry;
            carry = 0;
            if(digits[i]>=10){
                digits[i]%=10;
                carry=1;
            }
        }
        if(carry){digits.insert(digits.begin(), carry);}
        return digits;
    }
};*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0, n=digits.size()-1;
        digits[n] += 1;
        while(n>=0){
            digits[n] += carry;
            carry = 0;
            if(digits[n]==10){digits[n]=0; carry=1;}
            else{break;}
            n--;
        }
        if(carry){digits.insert(digits.begin(), carry);}
        return digits;
    }
};
