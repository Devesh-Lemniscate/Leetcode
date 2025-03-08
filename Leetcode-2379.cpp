class Solution {
    public:
        int minimumRecolors(string str, int k) {
            int n = str.size();
            int mn = INT_MAX;
    
            for (int i = 0; i <= n - k; i++) {  
                int cnt = 0;
                for (int j = i; j < i + k; j++) if (str[j] == 'W') cnt++;
                mn = min(mn, cnt); 
            }  
            return mn;
        }
    };
    