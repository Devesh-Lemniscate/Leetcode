/*
 * Problem 1448: Count Good Nodes in Binary Tree
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
    void check(TreeNode* root, int &cnt, int mx){
        if(!root) return ;
        if(root->val >= mx) {
            mx = root->val;
            cnt++;
        }
        check(root->left, cnt, mx);
        check(root->right, cnt, mx);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        check(root, cnt, INT_MIN);
        return cnt;
    }
};