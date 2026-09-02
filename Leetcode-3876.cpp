/*
 * Problem 3876: Construct Uniform Parity Array II
 * Language: C++
 */
class Solution {
public:
    bool uniformArray(vector<int>& nums){
        unordered_set<int> odd, even;
        int mini = INT_MAX;
        for(auto it: nums){
            if(it & 1) odd.insert(it);
            else even.insert(it);
            mini = min(mini, it);
        }
        int n = nums.size();
        if(odd.size() == n || even.size()==n) return true;
        long long countOdd = 0;
        if(mini % 2 == 0) return false;
        countOdd = odd.size() + even.size()*odd.size();
        return countOdd >= n;
    }
};