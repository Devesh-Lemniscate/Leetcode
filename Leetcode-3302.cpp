/*
 * Problem 3302: Find the Lexicographically Smallest Valid Sequence (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> last(m, -1);
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                last[j] = ptr;
                ptr--;
            }
        }
        vector<int> result;
        bool mismatch_used = false;
        for (int i = 0, j = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                result.push_back(i);
                j++;
            } else if (!mismatch_used && (j == m - 1 || last[j + 1] > i)) {
                result.push_back(i);
                mismatch_used = true;
                j++;
            }
        }
        if(result.size() == m) return result;
        else return {};
    }
};