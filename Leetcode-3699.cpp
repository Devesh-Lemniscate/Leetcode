/*
 * Problem 3699: Number of ZigZag Arrays I (POTD)
 * Language: C++
 */
class Solution {
public:
    int len = 0 ;
    int mod = 1e9 + 7 ;
    int dp[2001][2001][2] ;
    long long helper(int index , int num , bool dir , int n) {
        if( index == n ) return 1 ;

        if( dp[index][num][dir] != -1 ) return dp[index][num][dir] ;

        long long zigzag = 0, samePos = 0 ;
        if( dir == 0 && num -1 >= 0 ) {
            zigzag = helper(index + 1, num-1 , !dir , n) ;
            samePos = helper(index , num-1 , dir , n) ;
        }

        if( dir ==1 && num+1 <= len) {
            zigzag = helper(index + 1 , num+1 , !dir , n) ;
            samePos = helper(index , num+1 , dir , n) ;
        }

        return  dp[index][num][dir] = (samePos + zigzag)%mod ;

    }
    int zigZagArrays(int n, int l, int r) {
        len = r-l ;
        memset(dp , -1 , sizeof(dp)) ;
        return (2*1LL*helper(0 , 0 , 1 , n))%mod ;
    }
};