/*
 * Problem 1606: Find Servers That Handled Most Number of Requests (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> count(k, 0);
        set<int> st;
        for(int i = 0; i < k; i++) st.insert(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            int arrive = arrival[i], weight = load[i];
            while(pq.size() && pq.top().first <= arrive){
                st.insert(pq.top().second);
                pq.pop();
            }
            if(st.empty()) continue;
            int target = i % k;
            auto it = st.lower_bound(target);
            if(it == st.end()){
                it = st.begin();
            }
            int server = *it;
            count[server]++;
            maxi = max(maxi, count[server]);
            pq.push({arrive+weight, server});
            st.erase(it);
        }
        vector<int> ans;
        for(int i = 0; i < k; i++) if(count[i] == maxi) ans.push_back(i);
        return ans;
    }
};