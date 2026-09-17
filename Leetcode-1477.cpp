/*
 * Problem 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum (POTD)
 * Language: C++
 */
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n, INT_MAX), suffix(n, INT_MAX);

        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (mp.find(sum - target) != mp.end()) {
                int j = mp[sum - target];
                prefix[i] = i - j;
            }

            if (i > 0)
                prefix[i] = min(prefix[i], prefix[i - 1]);

            mp[sum] = i;
        }

        mp.clear();
        mp[0] = n;

        sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];

            if (mp.find(sum - target) != mp.end()) {
                int j = mp[sum - target];
                suffix[i] = j - i;
            }

            if (i < n - 1)
                suffix[i] = min(suffix[i], suffix[i + 1]);

            mp[sum] = i;
        }

        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] != INT_MAX && suffix[i + 1] != INT_MAX)
                ans = min(ans, prefix[i] + suffix[i + 1]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
