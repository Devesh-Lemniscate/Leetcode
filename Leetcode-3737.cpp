/*
 * Problem 3737: Count Subarrays With Majority Element I (POTD)
 * Language: C++
 */
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> count(n + 1, 0);

        for (int i = 0; i < n; i++) {
            count[i + 1] = count[i] + (nums[i] == target ? 1 : -1);
        }

        long long ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (count[r + 1] - count[l] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};