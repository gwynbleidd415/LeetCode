class Solution {
private:
    // void printMatrix(vector<vector<int>> &matrix){
    //     cout << "[";
    //     for(auto &arr: matrix){
    //         cout << "[";
    //         for(auto &el: arr){
    //             cout << el <<",";
    //         }
    //         cout << "],";
    //     }
    //     cout << "]\n";
    // }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int n{(int)matrix.size()}, m{(int)matrix.front().size()};
        // vector<bool> row0(n), col0(m);
        // for(int i{0};i<n;++i)
        //     for(int j{0};j<m;++j)
        //         if(matrix[i][j] == 0) row0[i] = col0[j] = true;
        // for(int i{0};i<n;++i){
        //     if(!row0[i]) continue;
        //     for(int j{0};j<m;++j) matrix[i][j] = 0;
        // }
        // for(int i{0};i<m;++i){
        //     if(!col0[i]) continue;
        //     for(int j{0};j<n;++j) matrix[j][i] = 0;
        // }

        int n{(int)matrix.size()}, m{(int)matrix.front().size()};
        bool firstRow0{false}, firstCol0{false};
        for(int i{0};i<n;++i) {
            if(matrix[i][0] == 0){
                firstCol0 = true;
                break;
            }
        }
        for(int i{0};i<m;++i) {
            if(matrix[0][i] == 0){
                firstRow0 = true;
                break;
            }
        }
        for(int i{1};i<n;++i){
            for(int j{1};j<m;++j){
                if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        // printMatrix(matrix);
        // for(int i{1};i<n;++i){
        //     if(matrix[i][0] != 0) continue;
        //     for(int j{1};j<m;++j) matrix[i][j] = 0;
        // }
        // for(int i{1};i<m;++i){
        //     if(matrix[0][i] != 0) continue;
        //     for(int j{1};j<n;++j) matrix[j][i] = 0;
        // }
        for(int i{1};i<n;++i){
            for(int j{1};j<m;++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(firstRow0){
            for(int j{0};j<m;++j) matrix[0][j] = 0;
        }
        if(firstCol0){
            for(int j{0};j<n;++j) matrix[j][0] = 0;
        }
    }
};