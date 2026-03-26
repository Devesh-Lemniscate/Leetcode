/*
 * Problem 3548: Equal Sum Grid Partition II (POTD)
 * Language: C++
 */
class Solution {
private:
    bool check_cut(long long sumA, long long sumB, 
                   int r1A, int r2A, int c1A, int c2A, 
                   int r1B, int r2B, int c1B, int c2B, 
                   unordered_map<long long, int>& freqA, 
                   unordered_map<long long, int>& freqB, 
                   const vector<vector<int>>& grid) {
        
        if (sumA == sumB) return true; 
        
        if (sumA > sumB) {
            long long diff = sumA - sumB;
            if (r1A == r2A) {
                if (grid[r1A][c1A] == diff || grid[r1A][c2A] == diff) return true;
            } 
            else if (c1A == c2A) {
                if (grid[r1A][c1A] == diff || grid[r2A][c1A] == diff) return true;
            } 
            else {
                if (freqA.count(diff) && freqA[diff] > 0) return true;
            }
        } else {
            long long diff = sumB - sumA;
            if (r1B == r2B) {
                if (grid[r1B][c1B] == diff || grid[r1B][c2B] == diff) return true;
            } else if (c1B == c2B) {
                if (grid[r1B][c1B] == diff || grid[r2B][c1B] == diff) return true;
            } else {
                if (freqB.count(diff) && freqB[diff] > 0) return true;
            }
        }
        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total_sum = 0;
        unordered_map<long long, int> total_freq;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total_sum += grid[i][j];
                total_freq[grid[i][j]]++;
            }
        }

        if (m > 1) {
            long long top_sum = 0;
            unordered_map<long long, int> top_freq;
            unordered_map<long long, int> bottom_freq = total_freq;
            
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; ++j) {
                    int val = grid[i][j];
                    top_sum += val;
                    top_freq[val]++;
                    bottom_freq[val]--;
                }
                
                long long bottom_sum = total_sum - top_sum;
                if (check_cut(top_sum, bottom_sum, 
                              0, i, 0, n - 1, 
                              i + 1, m - 1, 0, n - 1, 
                              top_freq, bottom_freq, grid)) {
                    return true;
                }
            }
        }

        if (n > 1) {
            long long left_sum = 0;
            unordered_map<long long, int> left_freq;
            unordered_map<long long, int> right_freq = total_freq;
            
            for (int j = 0; j < n - 1; ++j) {
                for (int i = 0; i < m; ++i) {
                    int val = grid[i][j];
                    left_sum += val;
                    left_freq[val]++;
                    right_freq[val]--;
                }
                
                long long right_sum = total_sum - left_sum;
                if (check_cut(left_sum, right_sum, 
                              0, m - 1, 0, j, 
                              0, m - 1, j + 1, n - 1, 
                              left_freq, right_freq, grid)) {
                    return true;
                }
            }
        }

        return false;
    }
};