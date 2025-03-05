class Solution {
    public:
        long long coloredCells(int n) {
            long long ans = 0;
            while(n-1){
                n--;
                ans+=n*4; 
            }
            return ans+1;
        }
    };