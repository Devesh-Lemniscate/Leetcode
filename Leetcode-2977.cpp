/*
 * Problem 2977: Minimum Cost to Convert String II (POTD)
 * Language: C++
 */
class Solution {
    const long long INF = 1e15;

    struct TrieNode {
        TrieNode* children[26];
        int id; 
        TrieNode() {
            fill(begin(children), end(children), nullptr);
            id = -1;
        }
    };

    void insert(TrieNode* root, const string& s, int id) {
        TrieNode* curr = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->id = id;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        unordered_map<string, int> str2id;
        int id_counter = 0;
        
        auto getId = [&](const string& s) {
            if (str2id.find(s) == str2id.end()) {
                str2id[s] = id_counter++;
            }
            return str2id[s];
        };
        for (const string& s : original) getId(s);
        for (const string& s : changed) getId(s);
        int m = str2id.size();
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = str2id[original[i]];
            int v = str2id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < m; k++) {
            for (int i = 0; i < m; i++) {
                if (dist[i][k] == INF) continue; 
                for (int j = 0; j < m; j++) {
                    if (dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        TrieNode* root = new TrieNode();
        for (const string& s : original) {
            insert(root, s, str2id[s]);
        }

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i]) {
                dp[i] = min(dp[i], dp[i + 1]);
            }

            TrieNode* curr = root;
            for (int j = i; j < n; j++) {
                int charIdx = source[j] - 'a';
                if (!curr->children[charIdx]) break; 
                curr = curr->children[charIdx];

                if (curr->id != -1) {
                    int u = curr->id;
                    string targetSub = target.substr(i, j - i + 1);
                    if (str2id.count(targetSub)) {
                        int v = str2id[targetSub];
                        if (dist[u][v] != INF && dp[j + 1] != INF) {
                            dp[i] = min(dp[i], dist[u][v] + dp[j + 1]);
                        }
                    }
                }
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};