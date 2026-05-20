/*
 * Problem 2657: Find the Prefix Common Array of Two Arrays (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<int> ans(n,0), mp(n+1, 0), tp(n+1, 0);
        for(int i = 1; i < n+1; i++){
            mp[A[i-1]]++;
            tp[B[i-1]]++;
            for(int j = 0; j < n; j++){
                if(mp[j+1] && tp[j+1]) cnt++;
            }
            ans[i-1] = cnt;
            cnt = 0;
        }
        return ans;
    }
};