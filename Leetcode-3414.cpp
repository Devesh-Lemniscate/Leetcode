/*
 * Problem 3414: Maximum Score of Non-overlapping Intervals (POTD)
 * Language: C++
 */
class Solution {
private:
    struct State {
        long long weight = 0;
        vector<int> indices;

        bool isBetterThan(const State& other) const {
            if (weight != other.weight) {
                return weight > other.weight;
            }
            return indices < other.indices;
        }
    };

    State solve(const vector<vector<int>>& nums, int n) {
        vector<int> prev(n, -1);
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i) {
            endTimes[i] = nums[i][0]; 
        }

        for (int i = 0; i < n; ++i) {
            int startTime = nums[i][1];
            auto it = lower_bound(endTimes.begin(), endTimes.end(), startTime);
            int idx = distance(endTimes.begin(), it) - 1;
            prev[i] = idx;
        }

        vector<vector<State>> dp(5, vector<State>(n + 1));

        for (int k = 1; k <= 4; k++){
            for (int i = 1; i <= n; i++) {
                State best = dp[k][i-1];

                int currentWeight = nums[i - 1][2];
                int originalIdx = nums[i - 1][3];
                int p = prev[i - 1];

                State takeCandidate = dp[k - 1][p + 1];
                takeCandidate.weight += currentWeight;
                takeCandidate.indices.push_back(originalIdx);
                sort(takeCandidate.indices.begin(), takeCandidate.indices.end());

                if (takeCandidate.isBetterThan(best)) {
                    best = takeCandidate;
                }
                dp[k][i] = best;
            }
        }
        return dp[4][n];
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> nums;
        nums.reserve(n);
        for (int i = 0; i < n; ++i) {
            nums.push_back({intervals[i][1], intervals[i][0], intervals[i][2], i});
        }
        sort(nums.begin(), nums.end());
        State ans = solve(nums, n);
        return ans.indices;
    }
};