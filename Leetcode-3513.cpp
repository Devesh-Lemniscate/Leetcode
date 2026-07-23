/*
 * Problem 3513: Number of Unique XOR Triplets I (POTD)
 * Language: C++
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for(auto num: nums) m |= num;
        return n <= 2 ? n: m+1;
    }
};