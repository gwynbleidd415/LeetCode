class Solution {
private:
    int solution1(string &text1, string &text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i{0};i<n;++i) {
            for(int j{0};j<m;++j) {
                if(text1[i] == text2[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp.back().back();
    }
    int solution2(string &text1, string &text2) {
        int n = text1.size(), m = text2.size();
        vector<int> dp(m+1);
        int temp1{0}, temp2{0};
        for(int i{0};i<n;++i) {
            for(int j{0};j<m;++j) {
                temp1 = dp[j+1];
                if(text1[i] == text2[j]) dp[j+1] = temp2 + 1;
                else dp[j+1] = max(dp[j], dp[j+1]);
                temp2 = temp1;
            }
            temp2 = 0;
        }
        return dp.back();
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // return solution1(text1, text2);
        return solution2(text1, text2);
    }
};
