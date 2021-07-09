/*
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

/*class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        vector<int> count;
        for(auto x: arr){
            m[x] ++;
        }
        for(auto x: m){
            count.push_back(x.second);
        }
        if 
        
        sort(count.begin(), count.end());
        for(int i=1; i<count.size(); i++){
            if(count[i-1] == count[i]){return false;}
        }
        return true;
    }
};*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        set<int> count;
        for(auto x: arr){
            m[x] ++;
        }
        for(auto x: m){
            count.insert(x.second);
        }
        return count.size() == m.size();
    }
};
