/*
 * Problem 3163: String Compression III
 * Language: C++
 */
class Solution {
public:
    string compressedString(string word) {
        int count = 1;
        string ans = "";
        for(int i = 1; i < word.size(); i++){
            if(word[i] == word[i-1] && count != 9){
                count++;
            }else{
                char ch = '0' + count;
                ans.push_back(ch);
                ans.push_back(word[i-1]);
                count = 1;
            }
        }
        char ch = '0' + count;
        ans.push_back(ch);
        ans.push_back(word[word.size()-1]);
        return ans;
    }
};