class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n{(int)matrix.size()}, m{(int)matrix.front().size()};
        vector<bool> row0(n), col0(m);
        for(int i{0};i<n;++i)
            for(int j{0};j<m;++j)
                if(matrix[i][j] == 0) row0[i] = col0[j] = true;
        for(int i{0};i<n;++i){
            if(!row0[i]) continue;
            for(int j{0};j<m;++j) matrix[i][j] = 0;
        }
        for(int i{0};i<m;++i){
            if(!col0[i]) continue;
            for(int j{0};j<n;++j) matrix[j][i] = 0;
        }
    }
};