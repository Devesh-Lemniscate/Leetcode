/*
 * Problem 1871: Jump Game VII (POTD)
 * Language: C++
 */
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false;

        queue<int> q;
        q.push(0);
        
        int maxi = 0; 

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n - 1) return true;

            int start = max(curr + minJump, maxi + 1);
            int end = min(curr + maxJump, n - 1);

            for (int i = start; i <= end; i++) {
                if (s[i] == '0') {
                    q.push(i);
                }
            }

            maxi = max(maxi, curr + maxJump);
        }

        return false;
    }
};