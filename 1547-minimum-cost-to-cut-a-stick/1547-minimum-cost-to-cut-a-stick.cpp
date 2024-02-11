class Solution {
    int solution1(int n, vector<int>& cuts) {
        if(cuts.size() == 1) return n;
        int cn = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cn, vector<int>(cn));
        dp.front().front() = cuts[1];
        dp.back().back() = n - cuts[cn-2];
        for(int i{1};i+1<cn;++i) dp[i][i] = cuts[i+1] - cuts[i-1];
        for(int i{1};i<cn;++i) {
            for(int j{0};j+i<cn;++j) {
                dp[j][j+i] = min(dp[j+1][i+j], dp[j][i+j-1]);
                for(int k{j+1};k<j+i;++k) {
                    dp[j][j+i] = min(dp[j][j+i], dp[k+1][j+i] + dp[j][k-1]);
                }
                dp[j][j+i] += (i+j+1 == cn ? n : cuts[i+j+1]) - (j == 0 ? 0 : cuts[j-1]);
            }
        }
        for(int i{0};i<cn;++i) {
            for(int j{0};j<cn;++j) cout << dp[i][j] << ' ';
            cout << '\n';
        }
        return dp.front().back();
    }
public:
    int minCost(int n, vector<int>& cuts) {
        return solution1(n, cuts);
    }
};