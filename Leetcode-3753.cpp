/*
 * Problem 3753: Total Waviness of Numbers in Range II (POTD)
 * Language: C++
 */
class Solution {

private:
    struct node{
        long long wavy, cnt;
    };

    string s;
    node dp[17][2][2][11][11];
    bool vis[17][2][2][11][11];

    node helper(int idx, int tight, int start, int prev2, int prev1){
        if(idx == s.size()) return {0, 1};
        if(vis[idx][tight][start][prev2][prev1]) return dp[idx][tight][start][prev2][prev1];
        vis[idx][tight][start][prev2][prev1] = true;
        long long total = 0, count = 0;
        int lim = tight ? s[idx]-'0' : 9;
        for(int i = 0; i <= lim; i++){
            int nextTight = tight && (i == lim);
            if(!start && i == 0){
                node child = helper(idx+1, nextTight, 0, 10, 10);
                total += child.wavy;
                count += child.cnt;
            }else{
                int nPrev2, nPrev1;
                long long add = 0;
                if(!start){
                    nPrev2 = 10;
                    nPrev1 = i;
                }else{
                    if(prev2 != 10){
                        bool peak = (prev1 > prev2 && prev1 > i);
                        bool valley = (prev1 < prev2 && prev1 < i);
                        if(peak || valley) add = 1;
                    }
                    nPrev2 = prev1;
                    nPrev1 = i;
                }
                node child = helper(idx+1, nextTight, 1, nPrev2, nPrev1);
                total += child.wavy + add*child.cnt;
                count += child.cnt;
            }
        }
        return dp[idx][tight][start][prev2][prev1] = {total, count};
    }

    long long solve(long long num){
        if(num <= 0) return 0;
        s = to_string(num);
        memset(vis, 0, sizeof(vis));
        return helper(0, 1, 0, 10, 10).wavy;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1-1);
    }
};