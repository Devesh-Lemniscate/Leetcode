/*
 * Problem 3653: XOR After Range Multiplication Queries I (POTD)
 * Language: C++
 */
#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto query: queries){
            int l = query[0], r = query[1], k = query[2], v = query[3];
            for(int i = l; i <= r; i+=k) nums[i] = ((ll)nums[i] * (ll)v) % mod;
        }
        int ans = 0;
        for(auto it: nums) ans ^= it;
        return ans;
    }
};