/*
 * Problem 902: Numbers At Most N Given Digit Set
 * Language: C++
 */
class Solution {
private:
    int dp[11][2];
    string s;
    vector<string> digit;
    int solve(int idx, bool tight){
        if(idx == s.size()) return 1;
        if(dp[idx][tight] != -1) return dp[idx][tight];
        int upperBound = (tight) ? s[idx]-'0' : 9;
        int res = 0;
        for(int index = 0; index < digit.size(); index++){
            if(stoi(digit[index]) > upperBound  && tight) break;
            int newTight = (tight && stoi(digit[index]) == upperBound);
            res += solve(idx+1, newTight);
        }
        return dp[idx][tight]=res;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        digit = digits;
        memset(dp,-1,sizeof(dp));
        s = to_string(n);
        int res = 0;
        for(int i = 1; i < s.size(); i++) res += pow(digits.size(), i);
        return res+solve(0, 1);
    }
};