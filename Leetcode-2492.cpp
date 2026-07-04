/*
 * Problem 2492: Minimum Score of a Path Between Two Cities (POTD)
 * Language: C++
 */
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjacency(n+1);
        for(auto road: roads){
            adjacency[road[0]].push_back({road[1], road[2]});
            adjacency[road[1]].push_back({road[0], road[2]});
        }
        queue<int> bfs;
        unordered_set<int> visited;
        int mini = INT_MAX;
        bfs.push(1);
        visited.insert(1);
        while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();
            for(auto [neighbour, score]: adjacency[node]){
                mini = min(mini, score);
                if(!visited.count(neighbour)){
                    visited.insert(neighbour);
                    bfs.push(neighbour);
                }
            }
        }
        return ;
    }
};