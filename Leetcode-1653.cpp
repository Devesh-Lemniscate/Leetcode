/*
 * Problem 1653: Minimum Deletions to Make String Balanced (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.size();
        int countA = 0, countB = 0;
        
        for(int index = 0; index < len; index++){
            if(s[index] == 'a')
                countA++;
            else
                countB++;
        }
        
        if(countA == len || countB == len) 
            return 0;
        
        int currentCountA = 0, currentCountB = 0;
        int minimumCost = INT_MAX;
        
        for(int index = 0; index < len; index++){
            minimumCost = min(minimumCost, currentCountB + countA - currentCountA);

            if(s[index] == 'a')
                currentCountA++;
            else
                currentCountB++;
        }
        
        minimumCost = min(minimumCost, currentCountB + countA - currentCountA);
        
        return minimumCost;
    }
};