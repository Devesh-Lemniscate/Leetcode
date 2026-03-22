/*
 * Problem 3868: Minimum Cost to Equalize Arrays Using Swaps
 * Language: C++
 */
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> both, num1, num2;
        for(auto it: nums1){
            both[it]++;
            num1[it]++;
        }
        for(auto it: nums2){
            both[it]++;
            num2[it]++;
        }
        for(auto it: both) if(it.second & 1) return -1;
        int cost = 0;
        for(auto it: both){
            int num = it.first, freq = it.second / 2;
            cost += abs(num1[num] - freq);
        }
        return cost/2;
    }
};