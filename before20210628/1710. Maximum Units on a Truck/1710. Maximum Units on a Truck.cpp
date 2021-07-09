/*
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

 

Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
 

Constraints:

1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106
*/

/*class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int max_k = 0, ans = 0, num_of_boxes = 0;
        map<int, int> m;
        for(int i=0; i<boxTypes.size(); i++){
            num_of_boxes += boxTypes[i][0];
            max_k = max(max_k, boxTypes[i][1]);
            m[boxTypes[i][1]] += boxTypes[i][0];
        }
        truckSize = min(truckSize, num_of_boxes);
        while(truckSize){
            if(m[max_k]){
                ans += max_k;
                m[max_k] --;
                truckSize --;
            }else{max_k --;}
        }
        return ans;
    }
};*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        vector<pair<int, int>> new_box; // number of units per box, number of boxes
        for(auto x: boxTypes){
            new_box.push_back({x[1], x[0]});
        }
        sort(new_box.begin(), new_box.end());
        for(int i=new_box.size()-1; i>=0; i--){
            ans += min(truckSize, new_box[i].second) * new_box[i].first;
            truckSize -= min(truckSize, new_box[i].second);
        }
        return ans;
    }
};
