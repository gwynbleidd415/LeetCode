class Solution {
private:
    vector<vector<int>> solution1(int n) {
        int maxx{n*n};
        vector<vector<int>> ans(n, vector<int>(n));
        int cVal{1};
        int n2{n>>1};
        for(int i{0}, j{n-1};i<n2;++i, j-=2) {
            int x{i}, y{i};
            for(int z{0};z<j;++z) ans[x][y++] = cVal++;
            for(int z{0};z<j;++z) ans[x++][y] = cVal++;
            for(int z{0};z<j;++z) ans[x][y--] = cVal++;
            for(int z{0};z<j;++z) ans[x--][y] = cVal++;
        }
        if(n&1) ans[n2][n2] = cVal;
        return ans;
    }
    vector<vector<int>> solution2(int n) {
        int maxx{n*n};
        vector<vector<int>> ans(n, vector<int>(n));
        int cVal{1};
        int n2{n>>1};
        for(int i{0}, j{n-1};i<n2;++i, j-=2) {
            int x{i}, y{i};
            for(int z{0};z<j;++z) {
                ans[x][y+z] = cVal+z;
                ans[x+z][y+j] = cVal + j + z;
                ans[x+j][y+j-z] = cVal + (j<<1) + z;
                ans[x+j-z][y] = cVal + j*3 + z;
            }
            cVal += j<<2;
        }
        if(n&1) ans[n2][n2] = cVal;
        return ans;
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        // return solution1(n);
        return solution2(n);
    }
};
