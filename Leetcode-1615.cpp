/*
 * Problem 1615: Maximal Network Rank
 * Language: C++
 */
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        vector<vector<bool>> conn(n, vector<bool>(n, false));
        for(auto& road : roads) {
            deg[road[0]]++;
            deg[road[1]]++;
            conn[road[0]][road[1]] = true;
            conn[road[1]][road[0]] = true;
        }
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int curr = deg[i] + deg[j];
                if(conn[i][j]) curr--;
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }
};