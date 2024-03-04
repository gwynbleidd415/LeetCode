class Solution {
    int solution1(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.front().front() == 1 || obstacleGrid.back().back() == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid.front().size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp.front().front() = 1;
        for(int i{1};i<n;++i) {
            if(obstacleGrid[0][i] == 1) dp[0][i] = 0;
            else dp[0][i] = dp[0][i-1];
        }
        for(int i{1};i<m;++i) {
            if(obstacleGrid[i][0] == 1) dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0];
        }
        for(int i{1};i<m;++i) {
            for(int j{1};j<n;++j) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp.back().back();
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solution1(obstacleGrid);
    }
};
