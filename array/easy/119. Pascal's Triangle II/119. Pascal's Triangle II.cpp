/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33
*/

/*class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for(int i=0; i<rowIndex; i++){
            vector<int> tmp = res;
            res = {1};
            for(int j=1; j<tmp.size(); j++){
                res.push_back(tmp[j]+tmp[j-1]);
            }
            res.push_back(1);
        }
        return res;
    }
};*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for(int i=0; i<rowIndex; i++){
            for(int j=res.size()-1; j>=1; j--){
                res[j]+=res[j-1];
            }
            res.push_back(1);
        }
        return res;
    }
};
