/*
 * Problem 712: Minimum ASCII Delete Sum for Two Strings (POTD)
 * Language: C++
 */
class Solution {

private:
    string s1, s2;
    int n, m;
    int dp[1001][1001];
    int helper(int i, int j){
        if(i >= n){
            int sum = 0;
            if(j < m){
                for(int k = j; k < m; k++) sum += s2[k];
            }
            return sum;
        }
        if(j >= m){
            int sum = 0;
            if(i < n){
                for(int k = i; k < n; k++) sum += s1[k];
            }
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min({
            ((s1[i] != s2[j]) ? s1[i] + s2[j] + helper(i+1, j+1) : helper(i+1, j+1)),
            s1[i] + helper(i+1, j),
            s2[j] + helper(i, j+1)
        });
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        n = s1.size(), m = s2.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 0);
    }
};