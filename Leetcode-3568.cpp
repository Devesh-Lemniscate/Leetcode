/*
 * Problem 3568: Minimum Moves to Clean the Classroom (POTD)
 * Language: C++
 */
class Solution {
public:
    int minMoves(vector<string>& arr, int k) {
        int n = arr.size(), m = arr[0].size(), idx = 0;
        pair<int, int> p;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j]=='S') p = {i,j};
                else if(arr[i][j]=='L') mp[i*100+j] = idx++;
            }
        }
        int mx = (1<<idx), tot = mx-1;
        vector<vector<vector<vector<int>>>> vis(n, vector<vector<vector<int>>>(m, vector<vector<int>>(k+1, vector<int> (mx, 0))));
        queue<tuple<int, int, int, int, int>> q;
        int px = p.first, py = p.second;
        vis[px][py][k][0] = 1;
        q.emplace(px, py, k, 0, 0);
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(q.size()){
            auto [x, y, ener, msk, cnt] = q.front(); q.pop();
            if(msk == tot) return cnt;
            if(ener==0) continue;
            for(auto it: dir){
                int nx = x+it[0], ny = y+it[1];
                if(nx<0 || nx >= n || ny < 0 || ny >= m) continue;
                char ch = arr[nx][ny];
                if(ch=='X') continue;
                int nener = ener-1;
                if(ch=='R') nener = k;
                int nmsk = msk;
                if(ch=='L'){
                    int id = mp[nx*100+ny];
                    nmsk |= (1<<id);
                }
                if(!vis[nx][ny][nener][nmsk]){
                    vis[nx][ny][nener][nmsk] = true;
                    q.emplace(nx, ny, nener, nmsk, cnt+1);
                }
            }
        }
        return -1;
    }
};