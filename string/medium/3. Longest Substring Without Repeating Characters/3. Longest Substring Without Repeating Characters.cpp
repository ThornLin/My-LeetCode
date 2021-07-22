/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)
            return 0;
        int l=0, r=0, res=0;
        set<char> st;
        while(r<n){
            if(st.count(s[r])==0){
                st.insert(s[r]);
                res = max(res, (int)st.size());
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, res=0, sub_res=0;
        vector<int> v(128, 0);
        while(r<s.length()){
            if(v[s[r]]==0){
                v[s[r]]++;
                sub_res ++;
                res = max(res, sub_res);
                r++;
            }
            else{
                v[s[l]]--;
                sub_res--;
                l++;
            }
        }
        return res;
    }
};
