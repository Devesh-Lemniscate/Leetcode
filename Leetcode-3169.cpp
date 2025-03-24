class Solution {
    public:
        
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });
            int ans = meetings[0][0]-1, mx = INT_MIN;
            mx = max(meetings[0][1], mx);
            for(int i = 1; i < meetings.size(); i++){
                if(mx + 1 < meetings[i][0]) ans += meetings[i][0]-mx-1;
                mx = max(meetings[i][1], mx);
            }
            ans+=days-mx;
            return ans;
        }
    };