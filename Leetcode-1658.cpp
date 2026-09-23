/*
 * Problem 1658: Minimum Operations to Reduce X to Zero (POTD)
 * Language: C++
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int maxi = -1;   
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0;
        cout << sum - x << endl;
        for(int i = 0; i < n; i++){
            curr += nums[i];
            mp[curr] = i;    
            if(mp.count((curr - (sum-x)))) maxi = max(maxi, i - mp[curr-(sum-x)]);
        }
        if(maxi == -1) return -1;
        return n - maxi;
    }
};