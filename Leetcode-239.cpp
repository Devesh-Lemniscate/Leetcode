/*
 * Problem 239: Sliding Window Maximum
 * Language: C++
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        deque<int> dq;
        vector<int> answer;
        for(int index = 0; index < len; index++){
            while(!dq.empty() && nums[dq.back()] < nums[index]) dq.pop_back();
            int validIndex = index-k+1;
            while(!dq.empty() && dq.front() < validIndex) dq.pop_front();
            dq.push_back(index);
            if(index >= k-1) answer.push_back(nums[dq.front()]);
        }
        return answer;
    }
};