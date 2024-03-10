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
    int calcCurrentRow(int n, vector<int> &row) {
        stack<int> st;
        st.push(-1);
        int ans{0}, top;
        for(int i{0};i<n;++i) {
            while(st.size()>1 && row[st.top()]>=row[i]) {
                top = st.top(), st.pop();
                ans = max(ans, row[top]*(i-st.top()-1));
            }
            st.push(i);
        }
        return ans;
    }
    int solution2(vector<vector<char>>& matrix) {
        int ans{0};
        int n = matrix.size(), m = matrix.front().size();
        vector<int> row(m+1, 0);
        for(int i{0};i<n;++i) {
            for(int j{0};j<m;++j) {
                if(matrix[i][j] == '1') row[j] += 1;
                else row[j] = 0;
            }
            ans = max(ans, calcCurrentRow(m+1, row));
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // return solution1(matrix);
        return solution2(matrix);
    }
};