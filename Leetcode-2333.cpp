/*
 * Problem 2333: Minimum Sum of Squared Difference (POTD)
 * Language: C++
 */
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        vector<long long> diff(n);
        long long maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
        }

        long long low = 0, high = maxi, target = maxi;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long ops = 0;
            for (int i = 0; i < n; i++) {
                if (diff[i] > mid) {
                    ops += diff[i] - mid;
                }
            }
            if (ops <= k) {
                target = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (target == 0) return 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > target) {
                k -= (diff[i] - target);
                diff[i] = target;
            }
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] == target) {
                diff[i]--;
                k--;
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += diff[i] * diff[i];
        }
        return ans;
    }
};