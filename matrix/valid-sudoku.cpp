// https://leetcode.com/problems/valid-sudoku/

#include<vector>
#include<set>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row[9];
        set<char> col[9];
        set<char> mat[9];

        for ( auto i = 0; i < 9; i++ ) {
            for ( auto j = 0; j < 9; j++ ) {
                if ( board[i][j] == '.' ) continue;
                
                if ( row[i].count(board[i][j]) ) return false;
                else row[i].insert(board[i][j]);

                if ( col[j].count(board[i][j])) return false;
                else col[j].insert(board[i][j]);

                int mIdx = 3*(i/3) + (j/3); // Remember to be 
                if ( mat[mIdx].count(board[i][j]) ) return false;
                else mat[mIdx].insert(board[i][j]);
            }
        }

        return true;
    }
};
