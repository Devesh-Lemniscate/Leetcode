/*
 * Problem 3121: Count the Number of Special Characters II (POTD)
 * Language: C++
 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26, -1), up(26, -1);
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'a' && word[i]<='z') low[word[i]-'a'] = i;
            if(word[i] >= 'A' && word[i]<='Z' && up[word[i]-'A'] == -1) up[word[i]-'A'] = i;
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(low[i] != -1 && up[i] != -1)count += (low[i] < up[i]);
        }
        return count;
    }
};