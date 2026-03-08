/*
 * Problem 1980: Find Unique Binary String (POTD)
 * Language: C++
 */
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(auto it: nums) st.insert(bitset<32>(it).to_ulong());
        for(int i = 0; i < pow(2, n); i++){
            if(!st.count(i)) return (bitset<32>(i).to_string()).substr(32-n, n);
        }
        return "";
    }
};