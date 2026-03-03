/*
 * Problem 1545: Find Kth Bit in Nth Binary String (POTD)
 * Language: C++
 */
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        int num = (1 << (n-1));
        if(k == num) return '1';
        if(k < num) return findKthBit(n-1, k);
        else return findKthBit(n-1, (1 << n) - k) == '0' ? '1' : '0';
    }
};