/*
 * Problem 215: Kth Largest Element in an Array
 * Language: C++
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num: nums){
            if(pq.size() >= k && num > pq.top()){
                pq.pop();
                pq.push(num);
            }else if(pq.size() < k)pq.push(num);
        }
        return pq.top();
    }
};