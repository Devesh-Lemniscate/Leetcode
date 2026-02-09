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
        TreeNode* newNode = new TreeNode(tree[mid]);
        newNode->left = helper(tree, low, mid-1);
        newNode->right = helper(tree, mid+1, high);
        return newNode;
    }
    void inorder(vector<int> &tree, TreeNode* root){
        if(root == NULL) return;
        inorder(tree, root->left);
        tree.push_back(root->val);
        inorder(tree, root->right);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> tree;
        inorder(tree, root);
        return helper(tree, 0, tree.size()-1);
    }
};