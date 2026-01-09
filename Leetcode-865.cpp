/*
 * Problem 865: Smallest Subtree with all the Deepest Nodes (POTD)
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
public:
    int lvl(TreeNode* root){
        if(!root) return 0;
        return 1 + max(lvl(root->right), lvl(root->left));
    }
    TreeNode* help(TreeNode* root){
        if(root==NULL) return NULL;
        int l = lvl(root->left);
        int r = lvl(root->right);
        if(l==r) return root;
        else if(l>r) return help(root->left);
        else return help(root->right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans = help(root);
        return ans;
    }
};