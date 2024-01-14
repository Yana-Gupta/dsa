// https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    int minDep(TreeNode* root) {
        if ( !root ) return 0;
        if ( root->left && root->right ) return 1 + min(minDep(root->left), minDep(root->right));
        if ( root->left ) return 1 + minDep(root->left);
        if ( root->right ) return 1 + minDep(root->right);
        return 1;
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if ( root->left && root->right )  return 1 + min(minDep(root->left), minDep(root->right));
        if ( root->left ) return 1 + minDep(root->left);
        if ( root->right ) return 1 + minDep(root->right);
        return 1;
    }
};