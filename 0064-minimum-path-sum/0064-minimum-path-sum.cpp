class Solution {
    int solution1(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid.front().size()));
        dp[0][0] = grid[0][0];
        for(int i{1};i<grid.size();++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i{1};i<grid.front().size();++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i{1};i<grid.size();++i) {
            for(int j{1};j<grid.front().size();++j){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp.back().back();
    }
    int solution2(vector<vector<int>>& grid) {
        vector<int> dp(grid.front().size());
        dp[0] = grid[0][0];
        for(int i{1};i<grid.front().size();++i) {
            dp[i] = dp[i-1] + grid[0][i];
        }
        for(int i{1};i<grid.size();++i) {
            dp[0] = grid[i][0];
            for(int j{1};j<grid.front().size();++j){
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }
        return dp.back();
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return solution1(grid);
        return solution2(grid);
    }
};