// https://leetcode.com/problems/combination-sum/


class Solution {
public:

    vector<vector<int>> ans;

    void helper( vector<int>& candidates, int currSum, int target, int idx, vector<int> temp ) {
        // Bounding Condition
        if ( currSum > target ) 
            return;
        
        if ( idx == candidates.size() ) {
            if ( currSum == target ){
                ans.push_back(temp);
            }
            return;
        }

        // Inclusion Condition
        currSum += candidates[idx];
        temp.push_back(candidates[idx]);
        helper(candidates, currSum, target, idx, temp);

        // Exculsion Condition
        currSum -= candidates[idx];
        temp.pop_back();
        helper(candidates, currSum, target, idx + 1, temp);
        
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, 0, target, 0, temp);

        return ans;
    }
};