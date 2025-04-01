class Solution {
    public:
        long long helper(vector<vector<int>>& arr, int i, vector<long long> &dp){
            if(i>arr.size()-1)return 0;
            if(dp[i] != - 1) return dp[i];
            return dp[i] = max(arr[i][0]+helper(arr, i+arr[i][1]+1, dp), helper(arr, i+1, dp));
        }
        long long mostPoints(vector<vector<int>>& questions) {
            vector<long long> dp(questions.size()+1, -1);
            return helper(questions, 0, dp);
        }
    };