/*
 * Problem 3483: Unique 3-Digit Even Numbers (POTD)
 * Language: C++
 */
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        int ans = 0;

        for (int lastDigit = 0; lastDigit <= 8; lastDigit += 2) {
            if (freq[lastDigit] == 0) continue;
            
            freq[lastDigit]--; 
            for (int firstDigit = 1; firstDigit <= 9; firstDigit++) {
                if (freq[firstDigit] == 0) continue;
                
                freq[firstDigit]--;
                for (int middleDigit = 0; middleDigit <= 9; middleDigit++) {
                    if (freq[middleDigit] > 0) {
                        ans++; 
                    }
                }
                
                freq[firstDigit]++; 
            }
            
            freq[lastDigit]++;
        }

        return ans;
    }
};