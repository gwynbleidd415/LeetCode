class Solution {
    int solution1Helper(int k, vector<int>& prices, vector<vector<vector<int>>> &dp, int day, bool buy) {
        if(k == 0 || day == prices.size()) return 0;
        if(dp[k][day][buy]!=-1) return dp[k][day][buy];
        if(buy) {
            return dp[k][day][buy] = max(solution1Helper(k, prices, dp, day+1, false)-prices[day], solution1Helper(k, prices, dp, day+1, true));
        } else {
            return dp[k][day][buy] = max(solution1Helper(k-1, prices, dp, day+1, true)+prices[day], solution1Helper(k, prices, dp, day+1, false));
        }
    }
    int solution1(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(prices.size(), vector<int>(2, -1)));
        return solution1Helper(k, prices, dp, 0, true);
    }
    int solution2(int k, vector<int>& prices) {
        int n = prices.size(), n2{n-2};
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(n, vector<int>(2, 0)));
        for(int i{0};i<k;++i) dp[i].back().back() = prices.back();
        for(int i{n2};i>=0;--i) {
            dp[0][i][0] = max(dp[0][i+1][0], dp[0][i+1][1] - prices[i]);
            dp[0][i][1] = max(dp[0][i+1][1], prices[i]);
        }
        for(int i{1};i<k;++i) {
            for(int j{n2};j>=0;--j){
                dp[i][j][0] = max(dp[i][j+1][0], dp[i][j+1][1] - prices[j]);
                dp[i][j][1] = max(dp[i][j+1][1], prices[j] + dp[i-1][j+1][0]);
            }
        }
        return dp.back().front().front();
    }
    int solution3(int k, vector<int>& prices) {
        int n = prices.size(), n2{n-2};
        vector<vector<int>> dp(n, vector<int>(2, 0));
        int temp, prev;
        dp.back()[1] = prices.back();
        for(int i{0};i<k;++i) {
            prev = 0;
            for(int j{n2};j>=0;--j){
                temp = dp[j][0];
                dp[j][0] = max(dp[j+1][0], dp[j+1][1] - prices[j]);
                dp[j][1] = max(dp[j+1][1], prices[j] + prev);
                prev = temp;
            }
        }
        return dp.front().front();
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        // return solution1(k, prices);
        // return solution2(k, prices);
        return solution3(k, prices);
    }
};