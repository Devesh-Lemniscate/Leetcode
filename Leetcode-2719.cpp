/*
 * Problem 2719: Count of Integers
 * Language: C++
 */
const int mod = 1e9+7;
class Solution {
private:
    int mini, maxi;
    int dp[23][2][401];
    int solve(string &s, int idx, bool tight, int sum){
        if(idx == s.size()) return (sum >= mini && sum <= maxi);
        if(dp[idx][tight][sum] != -1) return dp[idx][tight][sum];
        int ub = (tight) ? s[idx]-'0': 9;
        int res = 0;
        for(int i = 0; i <= ub; i++){
            bool newTight = (tight && i==ub);
            res = ((res % mod) + (solve(s, idx+1, newTight, sum + i) % mod)) % mod; 
        }
        return dp[idx][tight][sum] = res % mod;
    }
    bool isValid(string &s){
        int sum = 0;
        for(auto it: s) sum += it-'0';
        return (sum >= mini && sum <= maxi);
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        mini = min_sum;
        maxi = max_sum;
        // int num = stoi(num1);
        // num--;
        // num1 = to_string(num);
        memset(dp, -1, sizeof(dp));
        int n1 = solve(num2, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        int n2 = solve(num1, 0, 1, 0); 
        return ((n1 - n2 + mod) % mod + isValid(num1)) % mod;
    }
};