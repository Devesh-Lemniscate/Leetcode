/*
 * Problem 1970: Last Day Where You Can Still Cross (POTD)
 * Language: C++
 */
class Solution {
private:
    bool check(int mid,vector<vector<int>>& cells, int &row, int &col){
        vector<vector<int>> grid(row, vector<int> (col, 0));
        for(int i = 0; i <= mid; i++){
            int r = cells[i][0], c = cells[i][1];
            r--; c--;
            grid[r][c] = 1;
        }
        queue<pair<int, int>> q;
        for(int c = 0; c < col; c++){
            if(grid[0][c] == 0){
                 q.push({0, c});
                 grid[0][c] = 1;
            }
        }
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        while(q.size()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            if(r == row-1) return true;
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i], nc = c + dy[i];
                if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                if(grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = cells.size()-1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid, cells, row, col)){
                ans = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return ans+1;
    }
};