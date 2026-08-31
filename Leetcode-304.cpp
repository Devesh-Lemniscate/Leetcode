/*
 * Problem 304: Range Sum Query 2D - Immutable
 * Language: C++
 */
class NumMatrix {
private:
    vector<vector<int>> nums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        nums.resize(n+1, vector<int>(m+1, 0)); 
        for(int i = 1; i <= n; i++) nums[i][1] = nums[i-1][1] + matrix[i-1][0];
        for(int j = 1; j <= m; j++) nums[1][j] = nums[1][j-1] + matrix[0][j-1];
        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= m; j++){
                nums[i][j] = matrix[i-1][j-1] + nums[i-1][j] + nums[i][j-1] - nums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return nums[row2+1][col2+1] - nums[row1][col2+1] - nums[row2+1][col1] + nums[row1][col1];

    }
};

/**
36-
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */