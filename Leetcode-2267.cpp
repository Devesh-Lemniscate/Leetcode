/*
 * Problem 2267: Check if There Is a Valid Parentheses String Path (POTD)
 * Language: C++
 */
class Solution {
private:
    int n, m;
    int dp[101][101][201];
    bool helper(int i, int j, int bal, vector<vector<char>>& grid){
        if(i >= n || j >= m) return false;
        if(dp[i][j][bal] != -1) return dp[i][j][bal];
        if(i==n-1 && j == m-1){
            if(grid[i][j] == ')' && bal){
                if(bal-1 == 0)return true;
                else return false;
            }else return false;
        }
        int ans = -1;
        if(grid[i][j] == '('){
            ans = helper(i+1, j, bal+1, grid) || helper(i, j+1, bal+1, grid);
        }else{
            if(bal > 0){
                ans = helper(i+1, j, bal-1, grid) || helper(i, j+1, bal-1, grid);
            }else ans = false;
        }
        return dp[i][j][bal] = ans;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 0, grid);
    }
};