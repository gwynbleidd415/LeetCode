class Solution {
private:
    void displayVector(vector<vector<int>> &dp) {
        for(auto &itr: dp) {
            for(auto &el: itr) cout << el << ' ';
            cout<<'\n';
        }
        cout << '\n';
    }
    int solution1(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i{0};i<n;++i) dp[i][i] = 1;
        int temp;
        // displayVector(dp);
        for(int i{1};i<n;++i) {
            for(int j{0};j+i<n;++j) {
                if(s[j] == s[j+i]) dp[j][j+i] = dp[j+1][j+i-1] + 2;
                else dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1]);
            }
            // displayVector(dp);
        }
        return dp.front().back();
    }
public:
    int longestPalindromeSubseq(string s) {
        return solution1(s);
    }
};