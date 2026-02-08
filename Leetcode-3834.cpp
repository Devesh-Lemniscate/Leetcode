/*
 * Problem 3834: Merge Adjacent Equal Elements
 * Language: C++
 */
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        vector<long long> res;
        for(int index = 0; index < nums.size(); index++){
            st.push(nums[index]);
            while(st.size()){
                long long val = st.top(); st.pop();
                if(st.size()){
                    if(val == st.top()){
                        st.pop();
                        st.push(val*2LL);
                    }else{
                        st.push(val);
                        break;
                    }
                }else{
                    st.push(val);
                    break;
                }
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};