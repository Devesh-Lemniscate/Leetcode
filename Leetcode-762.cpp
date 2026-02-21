/*
 * Problem 762: Prime Number of Set Bits in Binary Representation (POTD)
 * Language: C++
 */
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int primes = 0;
        unordered_set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for(int num = left; num <= right; num++){
            int cnt = 0;
            for(int i = 31; i >= 0; i--){
                if((1 << i) & num) cnt++;
            }
            if(st.count(cnt)) primes++;
        }
        return primes;
    }
};