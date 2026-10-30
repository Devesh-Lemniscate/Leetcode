/*
 * Problem 3970: Shortest Path With At Most K Consecutive Identical Characters (POTD)
 * Language: C++
 */
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        vector<int> dist(n, k + 1);
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> pq;

        pq.emplace(0, make_pair(1, 0));

        while (!pq.empty()) {
            long long d = pq.top().first;
            int run = pq.top().second.first, x = pq.top().second.second;
            pq.pop();


            if (run >= dist[x]) continue;
            if (x == n - 1) return d;
            dist[x] = run;

            for (auto [y, w] : adj[x]) {
                int r = labels[y] == labels[x] ? run + 1 : 1;

                if (r < dist[y])
                    pq.emplace(d + w, make_pair(r, y));
            }
        }

        return -1;
    }
};