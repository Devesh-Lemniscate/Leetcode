class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while(n){
                int num = n%3;
                n/=3;
                if(num==2) return false;
            }
            return true;
        }
    };