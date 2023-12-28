class Solution {
public:
    int uniquePaths(int m, int n) {
        // if(n <  1 || m < 1) return 0;
        // if(n == 1 && m == 1) return 1;

        // return uniquePaths(m-1, n) + uniquePaths(m, n-1);

        vector<vector<int>> dp(m, vector<int>(n));
        for(int i{0};i<m;++i) dp[i][0] = 1;
        for(int i{1};i<n;++i) dp[0][i] = 1;

        for(int i{1};i<m;++i){
            for(int j{1};j<n;++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp.back().back();
    }
};