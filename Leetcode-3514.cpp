/*
 * Problem 3514: Number of Unique XOR Triplets II (POTD)
 * Language: C++
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s1, s2;
        for(auto num1: nums){
            for(auto num2: nums){
                s1.insert(num1^num2);
            }
        }
        for(auto num: nums){
            for(auto elem: s1) s2.insert(num^elem);
        }
        return s2.size();
    }
};