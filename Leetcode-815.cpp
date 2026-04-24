/*
 * Problem 815: Bus Routes
 * Language: C++
 */
#define un unordered_map<int, vector<int>>
#define us unordered_set<int>
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        un adj;
        int n = routes.size();
        
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                adj[stop].push_back(i);
            }
        }

        queue<int> q;
        us visitedStops;
        us visitedBuses;

        q.push(source);
        visitedStops.insert(source);
        int ans = 0;

        while (!q.empty()) {
            int len = q.size();
            ans++;

            while(len--){
                int node = q.front(); q.pop();

                for (int it : adj[node]) {
                    if (visitedBuses.count(it)) continue;
                    visitedBuses.insert(it);

                    for (int nextStop : routes[it]) {
                        if (nextStop == target) return ans;
                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
