/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        map<string, int> m;
        int j=0;
        for(int i=0; i<strs.size(); i++){
            string sub_s=strs[i];
            sort(sub_s.begin(), sub_s.end());
            if(m.find(sub_s)!=m.end()){v[m[sub_s]].push_back(strs[i]);}
            else{m[sub_s]=j; v.push_back({strs[i]}); j++;}
        }
        return v;
    }
};

/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> res;
        for(int i=0; i<strs.size(); i++){
            string sub_s=strs[i];
            sort(sub_s.begin(), sub_s.end());
            m[sub_s].push_back(strs[i]);
        }
        for(auto x: m){
            res.push_back(x.second);
        }
        return res;
    }
};*/
