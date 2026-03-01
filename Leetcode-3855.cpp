/*
 * Problem 3855: Sum of K-Digit Numbers in a Range
 * Language: C++
 */
class Solution {
    int mod = 1e9 + 7;

    long long p(long long b, long long e) {
        long long res = 1;
        b %= mod;
        while (e > 0) {
            if (e % 2 == 1) res = (res * b) % mod;
            b = (b * b) % mod;
            e /= 2;
        }
        return res;
    }

public:
    int sumOfNumbers(int l, int r, int k) {
        long long sum = 0;
        long long c = r - l + 1;

        for (int i = l; i <= r; i++) sum += i;

        long long t1 = p(c, k - 1);
        long long t2 = (p(10, k) - 1 + mod) % mod;
        long long t3 = p(9, mod - 2);

        long long num = (sum * t1) % mod;
        num = (num * t2) % mod;
        num = (num * t3) % mod;

        return num;
    }
};