/*
 * Problem 476: Number Complement
 * Language: C++
 */
class Solution {
public:
    int findComplement(int n) {
        if(n == 0) return 1;
        long long mul = 1, ans = 0;
        while(n >= mul){
            if(!(n&mul)){
                ans += mul;
            }
            mul <<= 1;
        }
        return ans;
    }
};