/*
 * Problem 3105: Longest Strictly Increasing or Strictly Decreasing Subarray (POTD)
 * Language: C++
 */
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt = 0, mx = INT_MIN, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) cnt++;
            else{
                mx = max(mx,cnt);
                cnt = 0;
            }
        }
        mx = max(mx,cnt);
        cnt = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]) cnt++;
            else{
                mx = max(mx,cnt);
                cnt = 0;
            }
        }
        mx = max(mx, cnt);
        return mx+1;
    }
};