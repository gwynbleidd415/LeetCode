class Solution {
    bool existHelper(vector<vector<char>>& board, string &word, vector<vector<bool>> &visited, int i, int j, int k){
        if(k == word.size()) return true;
        if(i<0||j<0||i==board.size()||j==board.front().size()||visited[i][j]||board[i][j]!=word[k]) return false;
        ++k;
        visited[i][j] = true;
        bool ans = existHelper(board, word, visited, i+1, j, k) || existHelper(board, word, visited, i, j+1, k) || existHelper(board, word, visited, i-1, j, k) || existHelper(board, word, visited, i, j-1, k);
        visited[i][j] = false;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board.front().size()));

        for(int i{0};i<board.size();++i){
            for(int j{0};j<board.front().size();++j){
                if(existHelper(board, word, visited, i, j, 0)) return true;
            }
        }
        return false;
    }
};