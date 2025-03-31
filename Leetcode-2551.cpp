class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
            if(k==1 || k==n)return 0;
            vector<int> ans;
            for(int i = 0; i < n-1; i++) ans.push_back(weights[i]+weights[i+1]);
            sort(ans.begin(), ans.end());
            long long mx = 0, mn = 0;
            for(int i = 0; i < k-1; i++){
                mx += ans[n-2-i];
                mn += ans[i];
            }
            return mx-mn;
        }
    };