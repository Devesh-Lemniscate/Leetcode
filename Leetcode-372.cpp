/*
 * Problem 372: Super Pow
 * Language: C++
 */
class Solution {
private:
    int mod = 1337;
    int helper(int b, int e){
        b %= mod;
        int res = 1;
        while(e > 0){
            if(e & 1) res = (res * b) % mod;
            b = (b*b) % mod;
            e /= 2;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0) return 1;
        int last = b.back(); b.pop_back();
        int ans = superPow(a, b);
        int p1 = helper(ans, 10);
        int p2 = helper(a, last);
        return (p1 * p2) % mod;
    }
};