/*
 * Problem 1009: Complement of Base 10 Integer (POTD)
 * Language: C++
 */
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mul = 1, ans = 0;
        while(n >= mul){
            if(!(n&mul)){
                ans += mul;
            }
            mul <<= 1;
        }
        return ans;
    }
};