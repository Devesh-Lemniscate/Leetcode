/*
 * Problem 56: Merge Intervals
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int x = intervals[0][0], y = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            // [[1,10],[2,3],[4,5],[6,7],[8,9]]
            if(intervals[i][0] <= intervals[i-1][1]){
                y = max(intervals[i-1][1], intervals[i][1]);
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
            }else{
                ans.push_back({x, y});
                x = intervals[i][0];
                y = intervals[i][1];
            }
        }
        ans.push_back({x, y});
        return ans;
    }
};