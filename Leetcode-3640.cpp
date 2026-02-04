/*
 * Problem 3640: Trionic Array II (POTD)
 * Language: C++
 */
class Solution {
    vector<int> nums;
    vector<vector<long long>> dp;
    long long INF = 1e18;

public:
    long long helper(int i, int j) {
        if (i < 0) return -INF;
        if (i == 0) return -INF; 
        if (dp[i][j] != -1) return dp[i][j];

        long long res = -INF;

        if (j == 0) {
            if (nums[i] > nums[i-1]) {
                long long prev = helper(i - 1, 0);
                if (prev != -INF) res = max(res, prev + nums[i]);
                res = max(res, (long long)nums[i-1] + nums[i]);
            }
        }

        else if (j == 1) {
            if (nums[i] < nums[i-1]) {
                long long prevSame = helper(i - 1, 1);
                if (prevSame != -INF) res = max(res, prevSame + nums[i]);

                long long prevState = helper(i - 1, 0);
                if (prevState != -INF) res = max(res, prevState + nums[i]);
            }
        }


        else if (j == 2) {
            if (nums[i] > nums[i-1]) {
                long long prevSame = helper(i - 1, 2);
                if (prevSame != -INF) res = max(res, prevSame + nums[i]);

                long long prevState = helper(i - 1, 1);
                if (prevState != -INF) res = max(res, prevState + nums[i]);
            }
        }

        return dp[i][j] = res;
    }

    long long maxSumTrionic(vector<int>& arr) {
        nums = arr;
        int n = nums.size();
        dp.assign(n, vector<long long>(3, -1));

        long long ans = -INF;

        for (int i = 0; i < n; ++i) {
            ans = max(ans, helper(i, 2));
        }

        return ans;
    }
};