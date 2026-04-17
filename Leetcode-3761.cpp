/*
 * Problem 3761: Minimum Absolute Distance Between Mirror Pairs (POTD)
 * Language: C++
 */
class Solution {
public:
    int rev(int x){
        int ans = 0;
        while(x){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums){
        unordered_map<int, int> mp;
        mp[rev(nums[0])] = 0;
        int ans = INT_MAX;
        for(int j = 1; j < nums.size(); j++){
            if(mp.count(nums[j])){
                ans = min(ans, j - mp[nums[j]]);
            }
            mp[rev(nums[j])] = j;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};