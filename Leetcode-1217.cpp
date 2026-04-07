/*
 * Problem 1217: Minimum Cost to Move Chips to The Same Position
 * Language: C++
 */
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cnt = 0, n = position.size();
        for(auto it: position) if(it & 1) cnt++;
        return min(cnt, n-cnt);
    }
};