/*
 * Problem 1301: Number of Paths with Max Score (POTD)
 * Language: C++
 */
class Solution {
private:
    const int mod = 1e9+7;
    pair<int, int> solve(int i, int j, vector<string> &board, vector<vector<pair<int, int>>>&dp){
        if(i <0 || j < 0) return {INT_MIN, 0};
        if(i == 0 && j == 0) return {0, 1};
        if(board[i][j] == 'X') return {INT_MIN, 0};
        if(dp[i][j].first != -1) return dp[i][j];

        int curr = (board[i][j] == 'S' || board[i][j] == 'E') ? 0 : board[i][j]-'0';

        pair<int, int> up = solve(i-1, j, board, dp);
        pair<int, int> left = solve(i, j-1, board, dp);
        pair<int, int> diag = solve(i-1, j-1, board, dp);
        int maxi = max({up.first, left.first, diag.first});
        if(maxi < 0) return dp[i][j] = {INT_MIN, 0};

        int paths = 0;
        if(maxi == up.first) paths = (paths + up.second) % mod;
        if(maxi == left.first) paths = (paths + left.second) % mod;
        if(maxi == diag.first) paths = (paths + diag.second) % mod;

        return dp[i][j] = {maxi+curr, paths};
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {-1, 0}));

        auto ans = solve(n-1, n-1, board, dp);

        if(ans.first < 0) return {0, 0};
        return {ans.first, ans.second};
    }
};




















