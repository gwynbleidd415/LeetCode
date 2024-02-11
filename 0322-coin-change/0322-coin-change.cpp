class Solution {
private:
    int solution1(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX-1));
        for(int i{0};i<=n;++i) dp[i][0] = 0;
        for(int i{0};i<n;++i) {
            int j{1};
            while(j<coins[i] && j<=amount) dp[i+1][j] = dp[i][j], ++j;
            while(j<=amount) dp[i+1][j] = min(dp[i][j], dp[i+1][j-coins[i]] + 1), ++j;
        }
        return dp.back().back() == INT_MAX-1 ? -1 : dp.back().back();
    }
    int solution2(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX-1);
        dp.front() = 0;
        for(int i{0};i<n;++i) {
            int j{coins[i]};
            while(j<=amount) dp[j] = min(dp[j], dp[j-coins[i]] + 1), ++j;
        }
        return dp.back() == INT_MAX-1 ? -1 : dp.back();
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // return solution1(coins, amount);
        return solution2(coins, amount);
    }
};