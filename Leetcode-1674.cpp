/*
 * Problem 1674: Minimum Moves to Make Array Complementary (POTD)
 * Language: C++
 */
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sweep(limit * 2 + 2, 0);

        for(int i=0; i <n/2; i++){
            int x = min(nums[i], nums[n-i-1]), y = max(nums[i], nums[n-i-1]);
            sweep[2] += 2;
            sweep[x+1] -= 1;
            sweep[x+y] -= 1;
            sweep[x+y+1] += 1;
            sweep[y+limit+1] += 1;
        }

        int mini = n, curr = 0;
        for(int i = 2; i <= 2*limit; i++){
            curr += sweep[i];
            mini = min(mini, curr);
        }
        return mini;
    }
};