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
public:
    int maxProfit(int k, vector<int>& prices) {
        return solution1(k, prices);
    }
};