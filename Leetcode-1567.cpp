/*
 * Problem 1567: Maximum Length of Subarray With Positive Product
 * Language: C++
 */
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int posLen = 0, negLen = 0, maxLen = 0;
        for (auto &n : nums) {
            if (n == 0){
                posLen = 0;
                negLen = 0;
            } 
            else if (n > 0){
                posLen++;
                if (negLen > 0) negLen++; 
            }
            else{
                int tempPos = posLen;
                int tempNeg = negLen;
                if (tempNeg > 0) posLen = tempNeg + 1;
                else posLen = 0; 
                negLen = tempPos + 1;
            }
            maxLen = max(maxLen, posLen);
        }
        return maxLen;
    }
};