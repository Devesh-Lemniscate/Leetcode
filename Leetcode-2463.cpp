/*
 * Problem 2463: Minimum Total Distance Traveled (POTD)
 * Language: C++
 */
class Solution {
private:
    long long dp[101][101];
    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory){
        int n = robot.size(), m = factory.size();
        if(i == n) return 0;
        if(j == m) return 1e15;
        if(dp[i][j] != -1) return dp[i][j];
        long long ans = solve(i, j+1, robot, factory);
        long long price = 0;
        for(int k = 0; k < factory[j][1] && i+k < n; k++){
            price += abs(robot[i+k]-factory[j][0]);
            ans = min(ans, price + solve(i+k+1, j+1, robot, factory));
        }
        return dp[i][j] = ans;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(dp, -1LL, sizeof(dp));
        return solve(0, 0, robot, factory);
    }
};