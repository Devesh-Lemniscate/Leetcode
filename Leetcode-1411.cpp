/*
 * Problem 1411: Number of Ways to Paint N × 3 Grid (POTD)
 * Language: C++
 */
class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        
        long long a = 6; // all 3 different
        long long b = 6; // first and third same
        
        for (int i = 2; i <= n; i++) {
            long long na = (2 * a + 2 * b) % MOD;
            long long nb = (2 * a + 3 * b) % MOD;
            a = na;
            b = nb;
        }
        
        return (a + b) % MOD;
    }
};
