/*
 * Problem 2001: Number of Pairs of Interchangeable Rectangles
 * Language: C++
 */
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        unordered_map<double, long long> mp;
        for(auto it: rectangles){
            mp[(double)it[0] / (double)it[1]]++;
        }
        long long ans = 0;
        for(auto it: mp){
            long long num = it.second;
            if(num & 1){
                num = (num-1)/2;
                ans += it.second * num;
            }else{
                num >>= 1;
                ans += num * (it.second-1); 
            }
        }
        return ans;
    }
};