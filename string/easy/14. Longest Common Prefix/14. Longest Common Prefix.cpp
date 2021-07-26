/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        //sort(strs.begin(), strs.end());
        bool same=true;
        for(int i=0; i<strs[0].size(); i++){
            
            for(auto x: strs){
                if(strs[0][i]!=x[i]){same=false; break;}
            }
            if(same){res+=strs[0][i];}
            else{break;}
        }
        return res;
    }
};*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int x = strs.size()-1;
        string res="";
        sort(strs.begin(), strs.end());
        for(int i=0; i<strs[0].size(); i++){
            if(strs[0][i]==strs[x][i]){res+=strs[0][i];}
            else{break;}
        }
        return res;
    }
};
