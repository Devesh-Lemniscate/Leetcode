/*
 * Problem 190: Reverse Bits (POTD)
 * Language: C++
 */
class Solution {
public:
    int reverseBits(int n) {
        bitset<32> b(n);   
        int size = b.size();
        for (int i = 0; i < size/2; i++) {
            bool tmp = b[i];
            b[i] = b[size - 1 - i];
            b[size - 1 - i] = tmp;
        }
        return (int)b.to_ulong();  
    }
};
