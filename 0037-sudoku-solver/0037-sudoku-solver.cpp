class Solution {
private:
    bool isValid(vector<vector<char>> &board, char ch, int i, int j){
        for(int k{0};k<9;++k){
            if(board[i][k] == ch || board[k][j] == ch) return false;
        }
        int ls = (i/3 + 1)*3, rs = (j/3 + 1)*3;
        for(int x{ls-3};x<ls;++x){
            for(int y{rs-3};y<rs;++y){
                if(board[x][y] == ch) return false;
            }
        }
        return true;
    }
    bool solveSudokuHelper(vector<vector<char>> &board, int i, int j) {
        if(j == 9) ++i, j = 0;
        if(i == 9) return true;
        if(board[i][j] != '.') return solveSudokuHelper(board, i, j+1);
        for(char ch{'1'};ch<='9';++ch){
            if(isValid(board, ch, i, j)) {
                board[i][j] = ch;
                if(solveSudokuHelper(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board, 0, 0);
    }
};