/*
 * Problem 239: Sliding Window Maximum
 * Language: C++
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int index = 0; index < nums.size(); index++){
            while(dq.size() && dq.front() <= index - k) dq.pop_front();
            while(dq.size() && nums[dq.back()] < nums[index]) dq.pop_back();
            dq.push_back(index);
            if(index >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};