/*
 * Problem 316: Remove Duplicate Letters
 * Language: C++
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> firstSeen(27, INT_MAX), lastSeen(27, INT_MAX);
        for(int index = 0; index < s.size(); index++){
            if(firstSeen[s[index] - 'a'] == INT_MAX){
                firstSeen[s[index]-'a'] = index;
            }
        }
        for(int index = 0; index < s.size(); index++){
            lastSeen[s[index]-'a'] = index;
        }
        
        string ans = "";
        
        for(int idx = 0; idx < 26; idx++){
            int minLast = INT_MAX;
            for(int i = 0; i < 26; i++) {
                if(lastSeen[i] != INT_MAX) minLast = min(minLast, lastSeen[i]);
            }
            if(minLast == INT_MAX) break; 

            int currIdx = 26;
            for(int index = 0; index < 26; index++){
                if(lastSeen[index] != INT_MAX && firstSeen[index] <= minLast){
                    currIdx = index;
                    break;
                }
            }
            
            if(currIdx != 26){
                ans.push_back(currIdx + 'a');
                int pickedPos = firstSeen[currIdx]; 
                
                firstSeen[currIdx] = INT_MAX;
                lastSeen[currIdx] = INT_MAX;
                for(int i = 0; i < 26; i++){
                    if(lastSeen[i] != INT_MAX && firstSeen[i] < pickedPos){
                        int nextPos = pickedPos + 1;
                        while(nextPos < s.size() && s[nextPos] - 'a' != i) {
                            nextPos++;
                        }
                        firstSeen[i] = nextPos;
                    }
                }
            } else break;
        }
        return ans;
    }
};