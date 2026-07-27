/*
 * Problem 1464: Maximum Product of Two Elements in an Array (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num: nums){
            if(pq.size() < 2) pq.push(num);
            else{
                if(num > pq.top()){
                    pq.pop();
                    pq.push(num);
                }
            }
        }
        int num = pq.top(); pq.pop();
        return (num-1) * (pq.top()-1);
    }
};