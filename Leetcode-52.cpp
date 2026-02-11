/*
 * Problem 52: N-Queens II
 * Language: C++
 */
class Solution {
public:
    void help(int idx, vector<string> temp, vector<vector<string>> &ans, vector<int> row, vector<int> upper, vector<int> lower, int n){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(row[i]==0 && lower[i+idx]==0 && upper[n-1+idx-i]==0){
                temp[i][idx] = 'Q';
                row[i] = 1;
                lower[i+idx] = 1;
                upper[n-1+idx-i] = 1;
                help(idx+1, temp, ans, row, upper, lower, n);
                temp[i][idx] = '.';
                row[i] = 0;
                lower[i+idx] = 0;
                upper[n-1+idx-i] = 0;
            }
        }
    }
    int solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) temp[i] = s;
        vector<int> row(n), upper(2*n-1), lower(2*n-1);
        help(0, temp, ans, row, upper, lower, n);
        return ans.size();
    }
    int totalNQueens(int n) {
        return solveNQueens(n);
    }
};