/*
 * Problem 3120: Count the Number of Special Characters I (POTD)
 * Language: C++
 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26, 0), up(26, 0);
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'a' && word[i] <= 'z') low[word[i]-'a']++;
            else up[word[i]-'A']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++)
            if(low[i] && up[i])
                count++;

        return count;
    }
};