/*
 * Problem 57: Insert Interval
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& nums) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start, end;
        for(int ind = 0; ind < intervals.size();){
            start = intervals[ind][0], end = intervals[ind][1];
            
                while(ind < intervals.size() && end <= nums[1] && nums[0] <= end && nums[0] >= start){
                    start = min(start, nums[0]);
                    end = max(end, nums[1]);
                    ind++;
                }
            ind++;
            ans.push_back({start, end});
        }
        
        return ans;
    }
};