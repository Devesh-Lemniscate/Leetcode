/*
 * Problem 4026: Maximum Gap Between Stations
 * Language: C++
 */
class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        vector<int> left(n), right(n);
        int idx = 0;
        for (int i = 0; i < m && idx < n; i++) {
            if (station[i] == skill[idx]) {
                left[idx] = i;
                idx++;
            }
        }
        idx = n - 1;
        for (int i = m - 1; i >= 0 && idx >= 0; i--) {
            if (station[i] == skill[idx]) {
                right[idx] = i;
                idx--;
            }
        }
        
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, right[i] - left[i-1]);
        }
        
        return ans;
    }
};