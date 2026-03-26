/*
 * Problem 5: Longest Palindromic Substring
 * Language: C++
 */
class Solution {
private:
    int helper(const string &s,vector<vector<int>> &dp, int i, int j){   
        if(i==j || i>j) return 1;   
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]) dp[i][j]=helper(s,dp,i+1,j-1);
        else dp[i][j]=0;
        helper(s,dp,i+1,j);
        helper(s,dp,i,j-1);
        return dp[i][j];  
    }
    
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        helper(s,dp,0,n-1);
        int n1=0,n2=0;
        for(int i=0; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(dp[i][j]==1 && j-i>n2-n1){
                    n1=i;
                    n2=j;
                }
            }
        }    
        return s.substr(n1,n2-n1+1);
    }
};
