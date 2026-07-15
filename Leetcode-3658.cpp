/*
 * Problem 3658: GCD of Odd and Even Sums (POTD)
 * Language: C++
 */
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return __gcd(n*n, n*(n+1));
    }
};