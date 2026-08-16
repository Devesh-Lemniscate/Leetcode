/*
 * Problem 2029: Stone Game IX (POTD)
 * Language: C++
 */
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int mods[3] = {0};
        for (int stone : stones) {
            mods[stone % 3]++;
        }
        
        if (mods[0] % 2 == 0) {
            return min(mods[1], mods[2]) > 0;
        }
        return abs(mods[1] - mods[2]) > 2;
    }
};