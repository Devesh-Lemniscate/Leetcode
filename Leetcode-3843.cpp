/*
 * Problem 3843: First Element with Unique Frequency
 * Language: C++
 */
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp1, mp2;
        for(auto it: nums) mp1[it]++;
        for(auto it: mp1) mp2[it.second]++;
        for(auto it: nums){
            if(mp2[mp1[it]] == 1) return it;
        }
        return -1;
    }
};