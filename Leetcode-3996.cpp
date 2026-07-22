/*
 * Problem 3996: Even Number of Knight Moves
 * Language: C++
 */
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return ((start[0] + start[1]) & 1) == ((target[0] + target[1]) & 1);
    }
};