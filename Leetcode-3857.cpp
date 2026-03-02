/*
 * Problem 3857: Minimum Cost to Split into Ones
 * Language: C++
 */
class Solution {
public:
    int minCost(int n) {
        n--;
        return n * (n+1) / 2;
    }
};