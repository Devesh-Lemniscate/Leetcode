/*
 * Problem 3963: Create Grid With Exactly One Path (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string top(n, '.');
        ans.push_back(top);
        string other(n-1, '#');
        other.push_back('.');
        for(int i = 0; i < m-1; i++)
            ans.push_back(other);
        return ans;
    }
};