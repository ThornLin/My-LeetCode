/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    vector<string> res;
    
    void solve(int l, int r, string sub_s, int n){
        if(sub_s.size()==2*n){res.push_back(sub_s);}
        if(l<n){solve(l+1, r, sub_s+"(", n);}
        if(r<l){solve(l, r+1, sub_s+")", n);}
    }
    
    vector<string> generateParenthesis(int n) {
        solve(0, 0, "", n);
        return res;
    }
};
