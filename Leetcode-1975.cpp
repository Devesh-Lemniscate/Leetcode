/*
 * Problem 1975: Maximum Matrix Sum (POTD)
 * Language: C++
 */
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long n = matrix.size();
        long long cnt = 0;
        long long sum = 0, mini = INT_MAX;
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                if(matrix[i][j] < 0) cnt++;
                sum += abs(matrix[i][j]);
                mini = min(mini, abs((long long)matrix[i][j]));
            }
        }
        if(cnt % 2 == 0) return sum;
        else return sum - 2*mini;
    }
};