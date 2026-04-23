/*
 * Problem 2615: Sum of Distances (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        vector<long long> ans(n);
        for(auto it: mp){
            if(it.second.size() > 1){
                long long sum = 0, pre = 0;
                sum = accumulate(it.second.begin(), it.second.end(), 0LL);
                for(int i = 0; i < it.second.size(); i++){
                    long long left = (1LL * it.second[i] * i) - pre;
                    pre += it.second[i];
                    long long right = (sum - pre) - (1LL * it.second[i] * (it.second.size()-i-1));
                    ans[it.second[i]] = left + right;                   
                }
            }
        }
        return ans;
    }
};