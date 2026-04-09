/*
 * Problem 337: House Robber III
 * Language: C++
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int helper(TreeNode* root, unordered_map<TreeNode*, int> &dp){
        if(!root) return 0;
        if(dp.count(root)) return dp[root];
        int ans = 0;
        if(root->left) ans += helper(root->left->right, dp) + helper(root->left->left, dp);
        if(root->right) ans += helper(root->right->right, dp) + helper(root->right->left, dp);
        return dp[root] = max(ans + root->val, helper(root->right, dp) + helper(root->left, dp));
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return helper(root, dp);
    }
};