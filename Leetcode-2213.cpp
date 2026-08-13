/*
 * Problem 2213: Longest Substring of One Repeating Character (POTD)
 * Language: C++
 */
struct Node {
    int max_len;
    int prefix_len;
    char prefix_char;
    int suffix_len;
    char suffix_char;

    Node() 
        : max_len(0), prefix_len(0), prefix_char('\0'), suffix_len(0), suffix_char('\0') {}
    
    Node(char c) 
        : max_len(1), prefix_len(1), prefix_char(c), suffix_len(1), suffix_char(c) {}
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right, int left_size, int right_size) {
        Node parent;
        
        parent.prefix_char = left.prefix_char;
        parent.suffix_char = right.suffix_char;

        parent.max_len = max(left.max_len, right.max_len);
        
        if (left.suffix_char == right.prefix_char) {
            parent.max_len = max(parent.max_len, left.suffix_len + right.prefix_len);
        }

        if (left.prefix_len == left_size && left.suffix_char == right.prefix_char) {
            parent.prefix_len = left_size + right.prefix_len;
        } else {
            parent.prefix_len = left.prefix_len;
        }

        if (right.suffix_len == right_size && left.suffix_char == right.prefix_char) {
            parent.suffix_len = right_size + left.suffix_len;
        } else {
            parent.suffix_len = right.suffix_len;
        }

        return parent;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(s[start]);
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        
        int left_size = mid - start + 1;
        int right_size = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], left_size, right_size);
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = Node(val);
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }

        int left_size = mid - start + 1;
        int right_size = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], left_size, right_size);
    }

public:
    SegmentTree(const string& s) {
        n = s.size();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void update(int idx, char val) {
        update(1, 0, n - 1, idx, val);
    }

    int getMax() const {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMax();
        }

        return ans;
    }
};