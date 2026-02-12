/*
 * Problem 3713: Longest Balanced Substring I (POTD)
 * Language: C++
 */
class Solution {
public:
    int longestBalanced(string s) {
        int len = s.size();
        int maxi = 0, counter = 0, currentCount = 0;
        for(int indexi = 0; indexi < len; indexi++){
            vector<int> freqCount(26, 0);
            for(int indexj = indexi; indexj < len; indexj++){
                freqCount[s[indexj] - 'a']++;
                currentCount = freqCount[s[indexj] - 'a'];
                counter = 0;
                for(int indexk = 0; indexk < 26; indexk++){
                    if((freqCount[indexk] != 0 && freqCount[indexk] != currentCount)){
                        counter = 1;
                        break;
                    }
                }    
                if(counter == 0){
                    maxi = max(maxi, indexj - indexi + 1);
                }
            }
        }
        return maxi;
    }
};