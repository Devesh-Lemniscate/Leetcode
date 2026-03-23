/*
 * Problem 2120: Execution of All Suffix Instructions Staying in a Grid
 * Language: C++
 */
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m, 0);
        for(int i = 0; i < m; i++){
            int row = startPos[0], col = startPos[1];
            int steps = 0;
            for(int j = i; j < m; j++){
                if(s[j] == 'R') col++;
                if(s[j] == 'D') row++;
                if(s[j] == 'L') col--;
                if(s[j] == 'U') row--;
                if(row < 0 || row >= n || col < 0 || col >= n) break;
                steps++;
            }
            ans[i] = steps;
        }
        return ans;
    }
};