/*
 * Problem 3620: Network Recovery Pathways (POTD)
 * Language: C++
 */
class Solution {
private:
    bool isValid(long long mid, long long &k, vector<bool>& online, vector<vector<pair<int, int>>>& adjacency){
        int n = online.size();
        queue<pair<int, long long>> bfs;
        bfs.push({0, 0});
        
        vector<long long> dist(n, -1);
        dist[0] = 0;

        while(!bfs.empty()){
            auto [node, current_weight] = bfs.front();
            bfs.pop();
            
            if(current_weight > dist[node]) continue;
            if(node == n-1 && current_weight <= k) return true;
            
            for(auto [neighbour, wt]: adjacency[node]){
                if((online[neighbour] || neighbour == n-1) && wt >= mid){
                    long long next_weight = current_weight + wt;
                    if(next_weight <= k){
                        if(dist[neighbour] == -1 || next_weight < dist[neighbour]){
                            dist[neighbour] = next_weight;
                            bfs.push({neighbour, next_weight});
                        }
                    }
                }
            }
        }
        return false;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adjacency(n);
        
        long long max_edge = 0;
        for(auto edge: edges){
            adjacency[edge[0]].push_back({edge[1], edge[2]});
            if(edge[2] > max_edge) max_edge = edge[2];
        }

        long long low = 0, high = max_edge;
        int maxScore = -1;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isValid(mid, k, online, adjacency)){
                maxScore = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return maxScore;
    }
};