/*
 * Problem 453: Minimum Moves to Equal Array Elements (POTD)
 * Language: C++
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        return (accumulate(nums.begin(), nums.end(), 0)  - (nums.size() * (*min_l)))
    }
};

/*
5 4 4 

1  5  10 20  = 10
11 15 20 20  = 5
16 20 20 25 = 4
20 24 24 25 = 1
21 25 25 25 = 4
25 29 29 25 
*/