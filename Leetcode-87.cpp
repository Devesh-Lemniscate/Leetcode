/*
 * Problem 87: Scramble String
 * Language: C++
 */
class Solution {
string s1, s2;
int dp[31][31][31];
    bool helper(int i, int j, int len){
        if(len == 1) return s1[i] == s2[j];
        if(dp[i][j][len] != -1) return dp[i][j][len];
        for(int k = 0; k < len; k++){
            bool notTake = helper(i, j, k) && helper(i+k, j+k, len-k);
            if(notTake) return dp[i][j][len] = 1;
            bool take = helper(i, j+len-k, k) && helper(i+k, j, len-k);
            if(take) return dp[i][j][len] = 1;
        }
        return dp[i][j][len] = 0;
    }
public:
    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        this->s1 = s1;
        this->s2 = s2;
        return helper(0,0,s1.size());
    }
};