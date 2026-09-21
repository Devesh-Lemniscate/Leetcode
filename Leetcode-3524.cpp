/*
 * Problem 3524: Find X Value of Array I (POTD)
 * Language: C++
 */
class Solution {
private:
    int n, k;
    long long dp[100001][5][2];

    long long helper(int index, int remainder, int canTake, int target, vector<int>& nums) {
        if (index >= n) return 0;

        if (dp[index][remainder][canTake] != -1) {
            return dp[index][remainder][canTake];
        }

        long long ans = 0;
        int numRem = nums[index] % k;

        if (canTake == 0) {
            ans += helper(index + 1, 0, 0, target, nums);

            int newRem = numRem;
            if (newRem == target) ans++; 
            ans += helper(index + 1, newRem, 1, target, nums);
        } 
        else {
            int newRem = (remainder * numRem) % k;
            if (newRem == target) ans++; 
            ans += helper(index + 1, newRem, 1, target, nums);
        }

        return dp[index][remainder][canTake] = ans;
    }

public:
    vector<long long> resultArray(vector<int>& nums, int K) {
        n = nums.size();
        k = K;
        vector<long long> res(k, 0);

        for (int target = 0; target < k; target++) {
            memset(dp, -1, sizeof(dp));
            res[target] = helper(0, 0, 0, target, nums);
        }

        return res;
    }
};