/*
 * Problem 3411: Maximum Subarray With Equal Products (POTD)
 * Language: C++
 */

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unsigned long long product = 1;
            long long g = 0, l = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];

                g = gcd(g, (long long)nums[j]);
                l = l / gcd(l, (long long)nums[j]) * nums[j];

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};