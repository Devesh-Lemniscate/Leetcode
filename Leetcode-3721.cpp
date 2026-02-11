/*
 * Problem 3721: Longest Balanced Subarray II (POTD)
 * Language: C++
 */
class Solution {
    int treeMin[400005];
    int treeMax[400005];
    int lazy[400005];

    void push(int node) {
        if (lazy[node] != 0) {
            int left = 2 * node, right = 2 * node + 1;
            treeMin[left] += lazy[node];
            treeMax[left] += lazy[node];
            lazy[left] += lazy[node];
            
            treeMin[right] += lazy[node];
            treeMax[right] += lazy[node];
            lazy[right] += lazy[node];
            
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            treeMin[node] += val;
            treeMax[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        treeMin[node] = min(treeMin[2 * node], treeMin[2 * node + 1]);
        treeMax[node] = max(treeMax[2 * node], treeMax[2 * node + 1]);
    }

    int findLeftmost(int node, int start, int end, int target) {
        if (treeMin[node] > target || treeMax[node] < target) return -1;
        
        if (start == end) return start;

        push(node);
        int mid = (start + end) / 2;
        
        int res = findLeftmost(2 * node, start, mid, target);
        if (res == -1) {
            res = findLeftmost(2 * node + 1, mid + 1, end, target);
        }
        return res;
    }

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= 4 * n; ++i) {
            treeMin[i] = treeMax[i] = lazy[i] = 0;
        }

        unordered_map<int, int> lastPos;
        int maxLen = 0;

        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            int prev = lastPos.count(val) ? lastPos[val] : -1;
            int weight = (val % 2 == 0) ? 1 : -1;
            update(1, 0, n - 1, prev + 1, j, weight);

            int i = findLeftmost(1, 0, n - 1, 0);
            
            if (i != -1) {
                maxLen = max(maxLen, j - i + 1);
            }

            lastPos[val] = j;
        }

        return maxLen;
    }
};