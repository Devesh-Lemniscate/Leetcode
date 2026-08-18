/*
 * Problem 3471: Find the Largest Almost Missing Integer (POTD)
 * Language: C++
 */
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        bool start  = false, end = false;
        int n = nums.size();
        if(k >= n) return *max_element(nums.begin(), nums.end());
        if(k == 1){
            int maxi = -1;
            unordered_map<int, int> mp;
            for(int i = 0; i < n; i++) mp[nums[i]]++;
            for(auto it: mp){
                if(it.second == 1) maxi = max(maxi, it.first);
            }
            return maxi;
        }
        if(nums[0] == nums[n-1]) return -1;
        for(int i = 1; i < n-1; i++){
            if(nums[i] == nums[0]) start = true;
            if(nums[i] == nums[n-1]) end = true;
        }
        if(!start && !end) return max(nums[0], nums[n-1]);
        if(start && end) return -1;
        if(start) return nums[n-1];
        return nums[0];
    }
};