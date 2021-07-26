/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    vector<string> mappings  = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    
    void helper(string s, string digits, int i){
        if(digits.size()==i){res.push_back(s); return ;}
        
        for(auto x: mappings[digits[i]-'2']){
            helper(s+x, digits, i+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits==""){return res;}
        helper("", digits, 0);
        return res;
    }
};
