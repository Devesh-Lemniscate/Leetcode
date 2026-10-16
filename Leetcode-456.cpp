/*
 * Problem 456: 132 Pattern
 * Language: C++
 */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int maxi = INT_MIN;
        stack<int> st;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--){
            if(maxi > nums[i]) return true;
            else{
                while(st.size() && st.top() < nums[i]){
                    maxi = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};