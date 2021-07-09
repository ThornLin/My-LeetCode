/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
*/

/*class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool cr = checkRow(board);
        bool cc = checkColumn(board);
        bool cb = checkBox(board);
        return cr and cc and cb;
    }
    bool checkRow(vector<vector<char>>& board){
        for(auto x: board){
            for(int i=0; i<x.size(); i++){
                if(x[i]=='.'){continue;}
                if(find(x.begin()+i+1, x.end(), x[i])!=x.end()){return false;}
            }
        }
        return true;
    }
    //bool checkRow(vector<vector<char>>& board){
        unordered_map<int, vector<int>> m;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){continue;}
                if(find(m[i].begin(), m[i].end(), board[i][j])!=m[i].end()){return false;}
                else{m[i].push_back(board[i][j]);}
            }
        }
        return true;
    }//
    bool checkColumn(vector<vector<char>>& board){
        unordered_map<int, vector<int>> m;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){continue;}
                if(find(m[j].begin(), m[j].end(), board[i][j])!=m[j].end()){return false;}
                else{m[j].push_back(board[i][j]);}
            }
        }
        return true;
    }
    bool checkBox(vector<vector<char>>& board){
        unordered_map<int, vector<int>> m;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){continue;}
                int x = (i/3)*10 + j/3;
                if(find(m[x].begin(), m[x].end(), board[i][j])!=m[x].end()){return false;}
                else{m[x].push_back(board[i][j]);}
            }
        }
        return true;
    }
};*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(auto x: board){ // checkRow
            for(int i=0; i<x.size(); i++){
                if(x[i]=='.'){continue;}
                if(find(x.begin()+i+1, x.end(), x[i])!=x.end()){return false;}
            }
        }
        
        unordered_map<int, vector<int>> m_c;
        for(int i=0; i<9; i++){ // checkColumn
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){continue;}
                if(find(m_c[j].begin(), m_c[j].end(), board[i][j])!=m_c[j].end()){return false;}
                else{m_c[j].push_back(board[i][j]);}
            }
        }
        
        unordered_map<int, vector<int>> m_b;
        for(int i=0; i<9; i++){ // checkBox
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){continue;}
                int x = (i/3)*10 + j/3;
                if(find(m_b[x].begin(), m_b[x].end(), board[i][j])!=m_b[x].end()){return false;}
                else{m_b[x].push_back(board[i][j]);}
            }
        }
        return true;
    }
};
