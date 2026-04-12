/*
 * Problem 1320: Minimum Distance to Type a Word Using Two Fingers (POTD)
 * Language: C++
 */
class Solution {
private:
    int dp[301][27][27];
    int check(char a, int b){
        int x = a - 'A', y = b;
        int r1 = x/6, r2 = y/6;
        int c1 = x%6, c2 = y%6;
        return abs(r1-r2) + abs(c1-c2);
    }
    int solve(int idx, int f1p, int f2p, string &word){
        if(idx == word.size()) return 0;
        if(dp[idx][f1p+1][f2p+1] != -1) return dp[idx][f1p+1][f2p+1];
        int takef1 = 1e9, takef2 = 1e9;
        if(f1p == -1) takef1 = solve(idx+1, word[idx]-'A', f2p, word);
        else takef1 = (check(word[idx], f1p)) +solve(idx+1, word[idx]-'A', f2p, word);
        if(f2p == -1) takef2 = solve(idx+1, f1p, word[idx]-'A', word);
        else takef2 = check(word[idx], f2p)+solve(idx+1, f1p, word[idx]-'A', word);
        return dp[idx][f1p+1][f2p+1] = min(takef1, takef2);
    }
public:
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, -1, word);
    }
};