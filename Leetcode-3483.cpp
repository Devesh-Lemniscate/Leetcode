/*
 * Problem 3483: Unique 3-Digit Even Numbers (POTD)
 * Language: C++
 */
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;
        
        int U = 0; 
        int pairs_non_zero = 0; 
        for (int i = 1; i <= 9; i++) {
            if (freq[i] > 0) U++;
            if (freq[i] >= 2) pairs_non_zero++;
        }
        
        int T = U + (freq[0] > 0 ? 1 : 0); 
        int ans = 0;
        
        if (freq[0] >= 1) {
            ans += U * max(0, T - 2);          
            ans += pairs_non_zero;            
            if (freq[0] >= 2) ans += U;        
        }
        
        for (int L = 2; L <= 8; L += 2) {
            if (freq[L] == 0) continue;
            
            ans += max(0, U - 1) * max(0, T - 2);       
            ans += pairs_non_zero - (freq[L] >= 2 ? 1 : 0); 
            if (freq[L] >= 2) ans += max(0, U - 1);         
            if (freq[L] >= 2) ans += max(0, T - 1);         
            if (freq[L] >= 3) ans += 1;                    
        }
        
        return ans;
    }
};