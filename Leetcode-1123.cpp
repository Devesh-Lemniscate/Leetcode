class Solution {
    public:
        int height(TreeNode* root){
            if(root==NULL) return 0;
            return 1+max(height(root->right), height(root->left));
        }
        TreeNode* helper(TreeNode* root){
            if(root && height(root->right) == height(root->left)) return root;
            else if(root && height(root->right) > height(root->left)) return helper(root->right);  
            else return helper(root->left);
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            TreeNode* ans = helper(root);
            return ans;
        }
    };