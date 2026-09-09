/*
 * Problem 3871: Count Commas in Range II (POTD)
 * Language: C++
 */
class Solution {
public:
    long long countCommas(long long n) {
        long long comma = 1, num = 999;
        if(n <= num) return 0;
        long long ans = 0;
        while(num <= n){
            long long nextNum = num * 1000 + 999;
            long long count = 0;
            if(n > nextNum){
                count = nextNum - num;
            }else{
                count = n - num;
            }
            ans += count * comma;
            comma++;
            num = nextNum;
        }
        return ans;
    }
};