/*
 * Problem 486: Predict the Winner
 * Language: C++
 */
class Solution {
private:
    bool helper(int n, int m, vector<int> &nums, int i, int j, int turn){
        if(i > j) return n >= m;
        if(turn) return helper(n+nums[i], m, nums, i+1, j, 1-turn) || helper(n+nums[j], m, nums, i, j-1, 1-turn); 
        else return helper(n, m+nums[i], nums, i+1, j, 1-turn) && helper(n, m+nums[j], nums, i, j-1, 1-turn);  
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return helper(0,0,nums, 0, nums.size()-1, 1);
    }
};