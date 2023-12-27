class Solution {
    void printMatrix(vector<vector<int>>& matrix){
        cout << '[';
        for(auto &arr: matrix){
            cout << '[';
            for(auto el: arr){
                cout << el << ',';
            }
            cout << "],";
        }
        cout << "]\n";
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = (n >> 1), n1=n-1;
        int temp, x, y;
        for(int i{0};i<m;++i){
            for(int j{i};j<n1-i;++j){
                x = i, y = j;
                temp = matrix[x][y];
                for(int k{0};k<3;++k){
                    // cout << x << ' ' << y << '\n';
                    matrix[x][y] = matrix[n1-y][x];
                    x = x^y;
                    y = x^y;
                    x = n1 - (x^y);
                    // cout << k << ' ' << x << ' ' << y << '\n';
                }
                matrix[x][y] = temp;
                // printMatrix(matrix);
            }
        }
    }
};