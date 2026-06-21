/*
 * Problem 1833: Maximum Ice Cream Bars (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> arr(100001, 0);
        int cnt = 0;
        for(auto ele: costs) arr[ele]+=1;
        for(int i = 1; i < 100001; i++){
            while(arr[i] && coins > 0 && coins>=i){
                cnt++;
                coins-=i;
                arr[i]-=1;
            }
        }
        return cnt;
    }
};