/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1){return s;}
        int i=0, max_len=1, max_idx=0;
        while(i<n){
            int l=i, r=i;
            while(r+1<n and s[r]==s[r+1]){r++;}
            i = r+1;
            while(l-1>=0 and r+1<n and s[l-1]==s[r+1]){l--; r++;}
            int cur_len = r-l+1;
            if(cur_len > max_len){
                max_len = cur_len;
                max_idx = l;
            }
        }
        return s.substr(max_idx, max_len);
    }
};
