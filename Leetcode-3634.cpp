/*
 * Problem 3634: Minimum Removals to Balance Array (POTD)
 * Language: C++
 */
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int len = nums.size();
        int left = 0, right = 0;
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        while(left < len && right < len){
            long long num = nums[left];
            while(right < len && num * k >= (long long)nums[right]) right++;
            ans = min(ans, len-right+left);
            left++;
        }
        ans = min(ans, len-right+left);
        return ans;
    }
};