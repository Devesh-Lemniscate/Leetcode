/*
 * Problem 1288: Remove Covered Intervals (POTD)
 * Language: C++
 */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int>&b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 1, i = 1;
        int c = intervals[0][0], d = intervals[0][1];
        while(i < intervals.size()){
            int a = intervals[i][0], b = intervals[i][1];
            if(c <= a && b <= d) i++;
            else{
                count++;
                i++;
                c = a, d = b;
            }
        }

        return count;
    }
};