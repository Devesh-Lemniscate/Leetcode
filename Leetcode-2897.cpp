/*
 * Problem 2897: Apply Operations on Array to Maximize Sum of Squares (POTD)
 * Language: C++
 */
class Solution {
private:
    const int mod = 1e9+7;
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(32, 0);
        for(auto num: nums){
            for(int i = 0; i < 32; i++){
                if(num & (1 << i)) bitCount[i]++;
            }
        }

        long long ans = 0;
        while(k--){
            long long curr = 0;
            for(int i = 0; i < 32; i++){
                if(bitCount[i] > 0){
                    curr |= 1LL << i;
                    bitCount[i]--;
                }
            }
            ans = (ans + curr * curr) % mod;
        }
        return ans;
    }
};

/*
0010
0110
0101
1000
*/