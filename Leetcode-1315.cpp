/*
 * Problem 1315: Sum of Nodes with Even-Valued Grandparent
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
    void solve(TreeNode* root, int &ans){
        if(!root) return;
        if(root->val % 2 == 0){
            if(root->right && root->right->right) ans += root->right->right->val;
            if(root->right && root->right->left) ans += root->right->left->val;
            if(root->left && root->left->right) ans += root->left->right->val;
            if(root->left && root->left->left) ans += root->left->left->val;
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};