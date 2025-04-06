class Solution {
    private:
        vector<int> res;
        void helper(int i, vector<int>& nums, vector<int> &ans, vector<int> &dp){
            if(i>=nums.size()){
                if(ans.size() > res.size()){
                    res = ans;
                }
                return;
            }
            if((ans.size()==0 || nums[i]%ans.back()==0) && dp[i] < (int)ans.size()+1){
                dp[i] = ans.size()+1;
                ans.push_back(nums[i]);
                helper(i+1, nums, ans, dp);
                ans.pop_back();
            }
            helper(i+1, nums, ans, dp);
        }
    
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            vector<int> ans, dp(nums.size(), -1);
            sort(nums.begin(), nums.end());
            helper(0, nums, ans, dp);
            return res;
        }
    };