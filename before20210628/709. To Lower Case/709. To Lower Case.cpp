/*
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"
 

Constraints:

1 <= s.length <= 100
s consists of printable ASCII characters.
*/

class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i]-'A'>=0 and s[i]-'A'<26)
                ans += s[i]-'A'+'a';
            else
                ans += s[i];
        }
        return ans;
    }
};
