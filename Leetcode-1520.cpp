/*
 * Problem 1520: Maximum Number of Non-Overlapping Substrings (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }

        vector<int> valid_right(26, -1);
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) continue;
            int r = last[i];
            bool valid = true;
            for (int j = first[i]; j <= r; j++) {
                if (first[s[j] - 'a'] < first[i]) { 
                    valid = false;
                    break;
                }
                r = max(r, last[s[j] - 'a']); 
            }
            if (valid) valid_right[i] = r;
        }

        vector<pair<int, char>> distance;
        for (int i = 0; i < 26; i++) {
            if (valid_right[i] != -1) {
                distance.push_back({valid_right[i] - first[i] + 1, 'a' + i});
            }
        }
        sort(distance.begin(), distance.end());

        vector<string> ans;
        vector<int> lines(n, 0);

        for (auto p : distance) {
            int ch = p.second - 'a';
            int l = first[ch], r = valid_right[ch];

            bool canPlace = true;
            for (int j = l; j <= r; j++) {
                if (lines[j] == 1) {
                    canPlace = false;
                    break;
                }
            }

            if (canPlace) {
                ans.push_back(s.substr(l, r - l + 1));
                for (int j = l; j <= r; j++) lines[j] = 1;
            }
        }

        return ans;
    }
};