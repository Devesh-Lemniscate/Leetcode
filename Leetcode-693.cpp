/*
 * Problem 693: Binary Number with Alternating Bits (POTD)
 * Language: C++
 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !((n ^ (n >> 1)) & ((n ^ (long)(n >> 1)) + 1));
    }
};