class Solution {
private:
    int getMaxForIndex(int ii, int jj, int n, int m, vector<vector<char>> &matrix) {
        int ans{1}, maxj{m};
        for(int i{ii};i<n;++i) {
            if(matrix[i][jj] == '0') break;
            int j{jj+1};
            for(;j<maxj;++j) {
                if(matrix[i][j] == '0') break;
            }
            ans = max(ans, (i-ii+1)*(j-jj));
            maxj = j;
        }
        return ans;
    }
    int solution1(vector<vector<char>>& matrix) {
        int ans{0};
        int n = matrix.size(), m = matrix.front().size();
        for(int i{0};i<n;++i) {
            for(int j{0};j<m;++j) {
                if(matrix[i][j] == '1') {
                    ans = max(ans, getMaxForIndex(i, j, n, m, matrix));
                }
            }
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        return solution1(matrix);
    }
};