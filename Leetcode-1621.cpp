/*
 * Problem 1621: Number of Sets of K Non-Overlapping Line Segments (POTD)
 * Language: C++
 */
class Solution {
private:
    const int mod = 1e9+7;

    long long power(long long base, long long exp){
        long long res = 1;
        base %= mod;
        while(exp > 0){
            if(exp % 2) res = ((base % mod) * (res % mod)) % mod;
            base = ((base % mod) * (base % mod)) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n){
        return power(n, mod-2);
    }

public:
    int numberOfSets(int n, int k) {
        long long numerator = 1, denominator = 1;
        int N = n+k-1;
        for(int i = 1; i <= 2*k; i++){
            numerator = (numerator * (N - i + 1)) % mod;
            denominator = (denominator * i) % mod;
        } 
        return (numerator * modInverse(denominator)) % mod;
    }
};