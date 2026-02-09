/*
 * Problem 1382: Balance a Binary Search Tree (POTD)
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
    TreeNode* helper(vector<int> &tree, int low, int high){
        if(low > high) return NULL;
        int mid = low + (high - low) / 2;
        TreeNode* new
    }
    void inorder(vector<int> &tree, TreeNode* root){
        if(root == NULL) return root;
        inorder(tree, root->left);
        tree.push_back(root->val);
        inorder(tree, root->right);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> tree;
        inorder(tree, root);
    }
};