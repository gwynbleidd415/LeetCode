class Solution {
private:
    void solution1Helper(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        if(i<0 || j < 0 || i == grid.size() || j == grid.front().size() || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;
        solution1Helper(i+1, j, visited, grid);
        solution1Helper(i-1, j, visited, grid);
        solution1Helper(i, j+1, visited, grid);
        solution1Helper(i, j-1, visited, grid);
    }
    int solution1(vector<vector<char>>& grid) {
        int ans{0};
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.front().size()));
        for(int i{0};i<grid.size();++i) {
            for(int j{0};j<grid.front().size();++j) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    ++ans;
                    solution1Helper(i, j, visited, grid);
                }
            }
        }
        return ans;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        return solution1(grid);
    }
};