/*
 * Problem 1266: Minimum Time Visiting All Points (POTD)
 * Language: C++
 */
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i++) {
            int yaxis = abs(points[i][1] - points[i - 1][1]);
            int xaxis = abs(points[i][0] - points[i - 1][0]);
            ans += max(xaxis, yaxis);
        }
        return ans;
    }
};