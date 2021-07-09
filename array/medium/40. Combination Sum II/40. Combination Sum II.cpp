/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

/*class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candidates, int target, vector<int>& out, int start){
        if(target<0){return ;}
        if(target==0 and not(find(res.begin(), res.end(), out)!=res.end())){res.push_back(out); return ;}
        for(int i=start; i<candidates.size(); i++){
            //if(i>start and candidates[i]==candidates[i-1]){continue;}
            out.push_back(candidates[i]);
            helper(candidates, target-candidates[i], out, i+1);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, out, 0);
        return res;
    }
};*/

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candidates, int target, vector<int>& out, int start){
        if(target<0){return ;}
        if(target==0){res.push_back(out); return ;}
        //if(target==0 and not(find(res.begin(), res.end(), out)!=res.end())){res.push_back(out); return ;}
        for(int i=start; i<candidates.size(); i++){
            if(i>start and candidates[i]==candidates[i-1]){
                cout << i << endl;
                continue;}
            out.push_back(candidates[i]);
            helper(candidates, target-candidates[i], out, i+1);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, out, 0);
        return res;
    }
};
