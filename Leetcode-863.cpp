/*
 * Problem 863: All Nodes Distance K in Binary Tree
 * Language: C++
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, vector<int>> adj;
    void make(TreeNode *root){
        if(!root) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        make(root->left);
        make(root->right);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        make(root);
        vector<int> ans;
        queue<int> q;
        unordered_set<int> visited;

        q.push(target->val);
        visited.insert(target->val);

        int curr = 0;

        while (!q.empty()) {
            int size = q.size();
        
            if (curr == k) {
                while (size--) {
                    ans.push_back(q.front());
                    q.pop();
                }
                return ans;
            }
            for (int i = 0; i < size; i++) {
                int curr = q.front(); q.pop();
                for (int neighbor : adj[curr]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            curr++;
        }

        return ans;
    }
};