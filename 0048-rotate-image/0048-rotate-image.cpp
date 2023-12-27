class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = (n >> 1), n1=n-1;
        int x, y, x1, y1;
        for(int i{0};i<m;++i){
            for(int j{i};j<n1-i;++j){
                x = i, y = j;
                for(int k{0};k<3;++k){
                    x1 = n1-y, y1 = x;
                    swap(matrix[x][y], matrix[x1][y1]);
                    x = x1, y = y1;
                }
            }
        }
    }
};