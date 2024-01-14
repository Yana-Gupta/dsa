// https://leetcode.com/problems/path-sum-ii/

class Solution {
public:
    void solve(vector<int> temp, vector<vector<int>>& ans, int curr, int tar, TreeNode* root) {
        if ( !root ) return;

        if ( curr == tar && root->left == NULL && root->right == NULL ) {
            ans.push_back(temp);
            return;
        } 

        // Taking left 
        if ( root->left ) {
            temp.push_back(root->left->val);
            solve(temp, ans, curr + root->left->val, tar, root->left);
            temp.pop_back();
        }
        

        // Taking right 
        if ( root->right ) {
            temp.push_back(root->right->val);
            solve(temp, ans, curr + root->right->val, tar, root->right);
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        if (!root ) return ans;
        vector<int> temp;
        temp.push_back(root->val);
        solve(temp, ans, root->val, targetSum, root);
        return ans;
    }
};