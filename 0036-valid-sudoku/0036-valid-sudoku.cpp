class Solution {
    bool areRowsValid(vector<vector<char>>& board){
        vector<bool> arr(9);
        for(int i{0};i<9;++i){
            fill(arr.begin(), arr.end(), false);
            for(int j{0};j<9;++j){
                if(board[i][j]=='.') continue;
                if(arr[board[i][j] - '1']) return false;
                arr[board[i][j] - '1'] = true;
            }
        }
        return true;
    }
    bool areColumnsValid(vector<vector<char>>& board){
        vector<bool> arr(9);
        for(int i{0};i<9;++i){
            fill(arr.begin(), arr.end(), false);
            for(int j{0};j<9;++j){
                if(board[j][i]=='.') continue;
                if(arr[board[j][i] - '1']) return false;
                arr[board[j][i] - '1'] = true;
            }
        }
        return true;
    }
    bool areGridsValid(vector<vector<char>>& board){
        vector<bool> arr(9);
        int x, y, a, b;
        for(int i{0};i<9;++i){
            fill(arr.begin(), arr.end(), false);
            x = (i%3)*3, y = (i/3)*3;
            for(int j{0};j<9;++j){
                a = x + (j%3), b = y + (j/3);
                if(board[a][b]=='.') continue;
                if(arr[board[a][b] - '1']) return false;
                arr[board[a][b] - '1'] = true;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return areRowsValid(board) && areColumnsValid(board) && areGridsValid(board);
    }
};