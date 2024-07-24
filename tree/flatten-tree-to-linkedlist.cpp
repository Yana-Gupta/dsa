// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/



// Flatten binary tree 

// put the right to the left of the node 
// then put that node to the right of its parent 


class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if ( root == NULL ) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};