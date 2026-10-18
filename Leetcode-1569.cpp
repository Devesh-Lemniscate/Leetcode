/*
 * Problem 1569: Number of Ways to Reorder Array to Get Same BST (POTD)
 * Language: C++
 */
class Solution {
private:
    long long MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    void buildPascalTable(int n) {
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(left);
        long long rightWays = dfs(right);

        int L = left.size();
        int R = right.size();
        
        long long totalWays = comb[L + R][L];
        totalWays = (totalWays * leftWays) % MOD;
        totalWays = (totalWays * rightWays) % MOD;

        return totalWays;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        buildPascalTable(n);

        long long ans = dfs(nums);

        return (ans - 1 + MOD) % MOD;
    }
};