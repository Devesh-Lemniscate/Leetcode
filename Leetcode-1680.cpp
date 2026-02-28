/*
 * Problem 1680: Concatenation of Consecutive Binary Numbers (POTD)
 * Language: C++
 */
#define ll long long
const int mod = 1e9+7;

class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans = 0;
        int move = 0;
        
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) move++;
            ans = ((ans << move) | i) % mod;
        }
        
        return ans;
    }
};