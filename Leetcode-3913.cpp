/*
 * Problem 3913: Sort Vowels by Frequency
 * Language: C++
 */
class Solution {
private:
    bool isVowel(char alphabet){
        return alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u';
    }
public:
    string sortVowels(string s) {
        unordered_map<char, int> frequencyMap, rankOfVowel;
        string vowelString;
        int currentRank = 1;
        for(auto alphabet: s){
            if(isVowel(alphabet)){
                frequencyMap[alphabet]++;
                vowelString.push_back(alphabet);
                if(!rankOfVowel.count(alphabet)){
                    rankOfVowel[alphabet] = currentRank;
                    currentRank++;
                }
            }
        }
        sort(vowelString.begin(), vowelString.end(), [&](char firstAlphabet, char secondAlphabet){
            if(frequencyMap[firstAlphabet] == frequencyMap[secondAlphabet]){
                return rankOfVowel[firstAlphabet] < rankOfVowel[secondAlphabet];
            }
            return frequencyMap[firstAlphabet] > frequencyMap[secondAlphabet];
        });
        int currentIndex = 0;
        for(auto &alphabet: s){
            if(isVowel(alphabet)){
                alphabet = vowelString[currentIndex];
                currentIndex += 1;
            }
        }
        return s;
    }
};