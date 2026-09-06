/*
 * Problem 2281: Sum of Total Strength of Wizards
 * Language: C++
 */
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        stack<int> st;
        int n = strength.size();
        vector<long long> prefixSum(n+2, 0), prefixSumSum(n+2, 0);
        for(int i = 1; i <= n; i++){
            prefixSum[i] = (prefixSum[i-1] + strength[i-1]) % 1000000007;
        }
        for(int i = 1; i <= n + 1; i++){
            prefixSumSum[i] = (prefixSumSum[i-1] + prefixSum[i-1]) % 1000000007;
        }
        int ind = 0; 
        long long ans = 0;
        long long MOD = 1000000007;

        while(ind < n){
            while(!st.empty() && strength[ind] <= strength[st.top()]){
                long long curr = st.top();
                long long val = strength[curr];
                st.pop();
                long long left = -1;
                long long right = ind;
                if(!st.empty()) left = st.top();
                long long len3 = curr - left;
                long long len2 = right - curr;
                long long term1 = (prefixSumSum[right + 1] - prefixSumSum[curr + 1] + MOD) % MOD;
                long long term2 = (prefixSumSum[curr + 1] - prefixSumSum[left + 1] + MOD) % MOD;
                ans = (ans + val * ((len3 * term1 % MOD - len2 * term2 % MOD + MOD) % MOD) % MOD) % MOD;
            }
            st.push(ind);
            ind++;
        }
        while(!st.empty()){
            long long curr = st.top();
            long long val = strength[curr];
            st.pop();
            long long left = -1;
            long long right = ind;
            if(!st.empty()) left = st.top();
            long long len3 = curr - left;
            long long len2 = right - curr;
            long long term1 = (prefixSumSum[right + 1] - prefixSumSum[curr + 1] + MOD) % MOD;
            long long term2 = (prefixSumSum[curr + 1] - prefixSumSum[left + 1] + MOD) % MOD;
            ans = (ans + val * ((len3 * term1 % MOD - len2 * term2 % MOD + MOD) % MOD) % MOD) % MOD;
        }
        return ans;
    }
};