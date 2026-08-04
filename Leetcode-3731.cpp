/*
 * Problem 3731: Find Missing Elements (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = INT_MIN, mini = INT_MAX;
        for(auto num: nums){
            maxi = max(num, maxi);
            mini = min(num, mini);
        }
        vector<int> ans;
        for(int i = mini; i <= maxi; i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};