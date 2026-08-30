/*
 * Problem 57: Insert Interval
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int index = 0;
        int newStart = newInterval[0], newEnd = newInterval[1];

        while(index < n && intervals[index][1] < newStart) result.push_back(intervals[index++]);

        while(index < n && intervals[index][0] <= newEnd) {
            newStart = min(newStart, intervals[index][0]);
            newEnd = max(newEnd, intervals[index][1]);
            index++;
        }
        result.push_back({newStart, newEnd});

        while(index < n) result.push_back(intervals[index++]);
        
        return result;
    }
};