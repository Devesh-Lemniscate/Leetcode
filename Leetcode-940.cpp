/*
 * Problem 940: Distinct Subsequences II (POTD)
 * Language: C++
 */
class Solution {
private:
    const int mod = 1e9+7;
public:
    int distinctSubseqII(string s) {
        unordered_map<char, int> prevCount;
        long long ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(prevCount.count(s[i])){
                long long prev = ans % mod;
                ans = (( ans * 2 ) % mod - prevCount[s[i]] + mod) % mod;
                prevCount[s[i]] = prev;
            }else{
                prevCount[s[i]] = ans;
                ans = (ans * 2) % mod + 1;
            }
        }
        return ans % mod;
    }
};