/*
 * Problem 3635: Earliest Finish Time for Land and Water Rides II (POTD)
 * Language: C++
 */
class Solution {
private:
    int solve(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2){
        int mn = INT_MAX;
        for(int i = 0; i < s1.size(); i++){
            mn = min(mn, s1[i] + d1[i]);
        }
        int ans = INT_MAX;
        for(int i = 0; i < s2.size(); i++){
            ans = min(ans, max(mn, s2[i]) + d2[i]);
        }
        return ans;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(solve(landStartTime, landDuration, waterStartTime, waterDuration), solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};