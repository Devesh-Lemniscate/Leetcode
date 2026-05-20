/*
 * Problem 2657: Find the Prefix Common Array of Two Arrays (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n+1, 0), ans;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(++freq[A[i]] == 2) cnt++;
            if(++freq[B[i]] == 2) cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};