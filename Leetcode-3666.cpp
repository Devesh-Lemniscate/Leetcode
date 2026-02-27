/*
 * Problem 3666: Minimum Operations to Equalize Binary String (POTD)
 * Language: C++
 */
class Solution {
public:
    int minOperations(string s, int k) {
        int zeroes = 0;
        for(auto it: s) if(it == '0') zeroes++;
        if(zeroes == 0) return 0;
        int n = s.size();
        if(n==k) return (zeroes==n) ? 1 : -1;
        int rem = n-k;
        int odd =  max((zeroes+k-1)/k, (n-zeroes+rem-1)/rem);
        odd += ~odd & 1;
        int even = max((zeroes + k - 1)/k, (zeroes + rem -1)/ rem);
        even += even & 1;
        int res = INT_MAX;
        if((k&1)==(zeroes&1)) res = min(res, odd);
        if(~zeroes & 1) res = min(res, even);
        return res == INT_MAX ? -1 : res;
    }
};