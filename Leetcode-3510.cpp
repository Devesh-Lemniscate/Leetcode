/*
 * Problem 3510: Minimum Pair Removal to Sort Array II (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        vector<int> L(n), R(n);
        vector<long long> val(n); 
        for(int i = 0; i < n; i++) {
            val[i] = nums[i];
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[n - 1] = -1;
        int inv_count = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(int i = 0; i < n - 1; i++) {
            if(val[i] > val[i+1]) inv_count++;
            pq.push({val[i] + val[i+1], i});
        }
        vector<bool> valid(n, true);
        int ops = 0;
        while(inv_count > 0) {
            int u = -1;
            long long current_sum = -1;
            while(!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                long long s = top.first;
                int idx = top.second; 
                if(valid[idx] && R[idx] != -1 && val[idx] + val[R[idx]] == s) {
                    u = idx;
                    current_sum = s;
                    break;
                }
            }
            if(u == -1) break; 
            int v = R[u]; 
            if(L[u] != -1 && val[L[u]] > val[u]) inv_count--;
            if(val[u] > val[v]) inv_count--;
            if(R[v] != -1 && val[v] > val[R[v]]) inv_count--;
            val[u] += val[v]; 
            valid[v] = false; 
            ops++;
            int w = R[v]; 
            R[u] = w;  
            if(w != -1) L[w] = u; 
            if(L[u] != -1 && val[L[u]] > val[u]) inv_count++;
            if(R[u] != -1 && val[u] > val[R[u]]) inv_count++;
            if(L[u] != -1) pq.push({val[L[u]] + val[u], L[u]});
            if(R[u] != -1) pq.push({val[u] + val[R[u]], u});          
        }
        return ops;
    }
};