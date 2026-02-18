/*
 * Problem 3660: Jump Game IX
 * Language: C++
 */
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int len = nums.size();
        vector<int> pref(len), suff(len), ans(len);
        pref[0] = nums[0], suff[len-1] = nums[len-1];
        for(int i = 1; i < len; i++) pref[i] = max(nums[i], pref[i-1]);
        for(int i = len-2; i >= 0; i--) suff[i] = min(nums[i], suff[i+1]);
        ans[len-1] = pref[len-1];
        for(int i = len-2; i >= 0; i--){
            ans[i] = pref[i];
            if(pref[i] > suff[i+1]) ans[i] = ans[i+1];
        }
        return ans;
    }
};