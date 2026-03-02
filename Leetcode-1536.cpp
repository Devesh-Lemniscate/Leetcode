/*
 * Problem 1536: Minimum Swaps to Arrange a Binary Grid (POTD)
 * Language: C++
 */
class Solution {
private:
    int countZeroes(int row, vector<vector<int>>& grid){
        int count  = 0;
        for(int i = grid.size()-1; i >= 0; i--){
            if(grid[row][i] == 1) break;
            count++;
        }
        return count;
    }
    int swapNeeded(int row, vector<int>& pos){
        int num = pos[row], idx = -1;
        for(int i = row + 1; i < pos.size(); i++){
            if(pos[i] >= pos.size()-row-1){
                idx = i;
                break;
            }
        }
        if(idx == -1) return -1;
        int cnt = 0;
        for(int i = idx; i > row; i--){
            swap(pos[i], pos[i-1]);
            cnt++;
        }
        return cnt;
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zero, pos;
        for(int i = 0; i < n; i++){
            int zeroes = countZeroes(i, grid);
            pos.push_back(zeroes);
        }
        zero = pos;
        sort(zero.rbegin(), zero.rend());
        bool notPossible = false;
        for(int i = 0; i < n; i++){
            if(zero[i] >= n-i-1) continue;
            else{
                notPossible = true;
                break;
            }
        }
        if(notPossible) return -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(pos[i] < n-i-1){
                ans += swapNeeded(i, pos);
            }
        }
        return ans;
    }
};