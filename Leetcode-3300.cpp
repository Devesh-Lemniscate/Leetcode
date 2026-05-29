/*
 * Problem 3300: Minimum Element After Replacement With Digit Sum (POTD)
 * Language: C++
 */
class Solution {
private:
    int convert(int num){
        string s = to_string(num);
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            sum += s[i] - '0';
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto num: nums){
            mini = min(mini, convert(num));
        }
        return mini;
    }
};