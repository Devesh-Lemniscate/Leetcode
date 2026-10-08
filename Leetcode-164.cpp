/*
 * Problem 164: Maximum Gap
 * Language: C++
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        if (mini == maxi) return 0;

        int bucketSize = (maxi - mini + n - 2) / (n - 1);
        int num = (maxi - mini) / bucketSize + 1;

        vector<int> bucketMin(num, INT_MAX);
        vector<int> bucketMax(num, INT_MIN);

        for (int x : nums) {
            int idx = (x - mini) / bucketSize;

            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);
        }

        int ans = 0;
        int prevMax = mini;

        for (int i = 0; i < num; i++) {
            if (bucketMin[i] == INT_MAX)
                continue;

            ans = max(ans, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return ans;
    }
};