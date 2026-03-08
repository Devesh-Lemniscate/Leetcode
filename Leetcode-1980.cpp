/*
 * Problem 1980: Find Unique Binary String (POTD)
 * Language: C++
 */
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        for(auto ele: nums)st.insert(stoi(ele, NULL, 2));
        for(int i = 0;;i++)if(!st.count(i)) return bitset<16>(i).to_string().substr(16-nums.size());
        return "";
    }
};