// https://leetcode.com/problems/recover-binary-search-tree/description/

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
    void markNode(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if ( !root ) return;
        markNode(root->left, prev, first, end);
        if (prev) {
            if ( root->val < prev->val ) {
                if ( !first ) first = prev;
                end = root;
            }
        }
        prev = root;
        markNode(root->right, prev, first, end);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL, *first = NULL, *end = NULL;
        markNode(root, prev, first, end);
        swap(first->val, end->val);
        return;
    }
};