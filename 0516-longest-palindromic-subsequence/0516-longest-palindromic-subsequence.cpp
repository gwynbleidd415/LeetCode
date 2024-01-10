class Solution {
private:
    int solution1Helper(string &s, vector<vector<int>> &dp, int si, int ei) {
        if(si > ei) return 0;
        if(dp[si][ei]) return dp[si][ei];
        if(si == ei) return dp[si][ei] = 1;
        if(s[si] == s[ei]) return dp[si][ei] = solution1Helper(s, dp, si+1, ei-1) + 2;
        int ans1 = solution1Helper(s, dp, si+1, ei);
        int ans2 = solution1Helper(s, dp, si, ei-1);
        return dp[si][ei] = max(ans1, ans2);
    }
    int solution1(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i{0};i<n;++i) dp[i][i] = 1;
        return solution1Helper(s, dp, 0, s.size()-1);
    }
    int solution2(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i{0};i<n;++i) dp[i][i] = 1;
        int temp;
        for(int i{1};i<n;++i) {
            for(int j{0};j+i<n;++j) {
                if(s[j] == s[j+i]) dp[j][j+i] = dp[j+1][j+i-1] + 2;
                else dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1]);
            }
        }
        return dp.front().back();
    }
    int solution3(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i{0};i<n;++i) dp[i][i] = 1;
        int temp;
        for(int i{1};i<n;++i) {
            for(int j{0};j+i<n;++j) {
                if(s[j] == s[j+i]) dp[j][j+i] = dp[j+1][j+i-1] + 2;
                else dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1]);
            }
        }
        return dp.front().back();
    }
public:
    int longestPalindromeSubseq(string s) {
        return solution1(s);
        // return solution2(s);
        // return solution3(s);
    }
};