class Solution {
    int columnBinarySearch(vector<vector<int>>& matrix, int target) {
        int sz = matrix.size();
        int s{0}, e{sz-1}, m{};
        while(s<e) {
            m = (s+e+1)>>1;
            if(matrix[m][0] > target) {
                e = m-1;
            } else {
                s = m;
            }
        }
        return s;
    }
    bool rowBinarySearch(vector<vector<int>>& matrix, int target, int row) {
        int sz = matrix.front().size();
        int s{0}, e{sz-1}, m{};
        while(s<e) {
            m = (s+e+1)>>1;
            if(matrix[row][m] > target) {
                e = m-1;
            } else {
                s = m;
            }
        }
        return matrix[row][s] == target;
    }
    bool solution1(vector<vector<int>>& matrix, int target) {
        if(matrix.front().front() > target) return false;
        int row  = columnBinarySearch(matrix, target);
        return rowBinarySearch(matrix, target, row);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return solution1(matrix, target);
    }
};
