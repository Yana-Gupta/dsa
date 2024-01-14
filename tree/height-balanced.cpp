// https://leetcode.com/problems/balanced-binary-tree/

class Solution {
public:
    int calHeight(TreeNode* root) {
        if ( !root ) return 0;
        int l = calHeight(root->left);
        int r = calHeight(root->right);

        return 1 + max(l, r);
    }

    bool isBalanced1(TreeNode* root) {
        if ( !root ) return true;
        int left = calHeight(root->left);
        int right = calHeight(root->right);

        return abs(right - left ) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    bool isBalanced(TreeNode* root) {
        return isBalanced1(root);
    }
};