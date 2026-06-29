/*
 * Problem 1967: Number of Strings That Appear as Substrings in Word (POTD)
 * Language: C++
 */
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> words;
        for(int i = 0; i < word.size(); i++){
            for(int j = i; j <= word.size(); j++){
                string newWord = "";
                for(int k = i; k < j; k++){
                    newWord += word[k];
                }
                words.insert(newWord);
            }
        }
        int count = 0;
        for(auto pattern: patterns){
            if(words.count(pattern)) 
                count++;
        }
        return count;
    }
};