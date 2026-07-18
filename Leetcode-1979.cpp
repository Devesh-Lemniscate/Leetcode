/*
 * Problem 1979: Find Greatest Common Divisor of Array (POTD)
 * Language: C++
 */
class Solution {
public:
    int findGCD(vector<int>& nums) {
        return __gcd(*max_element(nums.begin(), nums.end()), *min_element(nums.begin(), nums.end()));
    }
};