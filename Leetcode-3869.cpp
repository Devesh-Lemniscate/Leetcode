/*
 * Problem 3869: Count Fancy Numbers in a Range
 * Language: C++
 */
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    long long dp[20][2][2][11][4][180];
    string str;
    bool isGoodSum[180];

    long long memo(int idx, bool tight, bool lz, int prev, int mono_state, int sum_digits) {
        if (idx == str.length()) {
            if (lz) return 1; 
            
            bool isGood = (mono_state != 3);
            return (isGood || isGoodSum[sum_digits]) ? 1 : 0;
        }

        if (dp[idx][tight][lz][prev][mono_state][sum_digits] != -1) {
            return dp[idx][tight][lz][prev][mono_state][sum_digits];
        }

        long long ans = 0;
        int limit = tight ? (str[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; digit++) {
            bool next_tight = tight && (digit == limit);
            bool next_lz = lz && (digit == 0);
            
            int next_prev = digit;
            int next_mono_state = mono_state;
            
            if (lz) {
                if (digit == 0) {
                    next_prev = 10;
                    next_mono_state = 0;
                } else {
                    next_mono_state = 0; 
                }
            } else {
                if (mono_state == 0) {
                    if (digit > prev) next_mono_state = 1;
                    else if (digit < prev) next_mono_state = 2;
                    else next_mono_state = 3;
                } else if (mono_state == 1) {
                    if (digit > prev) next_mono_state = 1;
                    else next_mono_state = 3;
                } else if (mono_state == 2) {
                    if (digit < prev) next_mono_state = 2;
                    else next_mono_state = 3;
                } else {
                    next_mono_state = 3;
                }
            }

            int next_sum = sum_digits + digit;
            ans += memo(idx + 1, next_tight, next_lz, next_prev, next_mono_state, next_sum);
        }

        return dp[idx][tight][lz][prev][mono_state][sum_digits] = ans;
    }

    long long solve(long long n) {
        if (n < 0) return 0;
        if (n == 0) return 1; 

        str = to_string(n);
        memset(dp, -1, sizeof(dp));
        return memo(0, true, true, 10, 0, 0);
    }

public:
    long long countFancy(long long l, long long r) {
        for (int i = 0; i < 180; ++i) {
            if (i < 10) {
                isGoodSum[i] = true;
            } else {
                string s = to_string(i);
                bool inc = true, dec = true;
                for (int j = 1; j < s.length(); ++j) {
                    if (s[j] <= s[j-1]) inc = false;
                    if (s[j] >= s[j-1]) dec = false;
                }
                isGoodSum[i] = (inc || dec);
            }
        }
        
        return solve(r) - solve(l - 1);
    }
};