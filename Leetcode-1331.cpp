/*
 * Problem 1331: Rank Transform of an Array (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        unordered_map<int, int> m;
        int pos = 1;
        for(auto ele: s){
            m[ele] = pos;
            pos++;
        }
        for(auto& ele: arr){
            ele = m[ele];
        }
        return arr;
    }
};