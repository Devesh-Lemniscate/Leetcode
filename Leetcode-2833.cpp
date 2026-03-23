/*
 * Problem 2833: Furthest Point From Origin
 * Language: C++
 */
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, both = 0;
        for(auto &move: moves){
            if(move == 'L') left++;
            else if(move == 'R') right++;
            else both++;
        }
        return abs(left - right) + both;
    }
};