/*
 * Problem 2444: Count Subarrays With Fixed Bounds
 * Language: C++
 */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        bool fmini = false, fmaxi = false;
        int start = 0, mini = 0, maxi = 0;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(num < minK || num > maxK){
                start = i+1;
                fmini = false;
                fmaxi = false;
            }
            if(num == minK){
                fmini = true;
                mini = i;
            }
            if(num == maxK){
                fmaxi = true;
                maxi = i;
            }
            if(fmini && fmaxi){
                ans += (long long)(min(mini, maxi) - start + 1);
            }
        }
        return ans;
    }
};