class Solution {
private:
    int solution1(string &s, string &t) {
        if(s.size() < t.size()) return 0;
        int m = s.size(), n = t.size();
        vector<vector<long>> dp(m, vector<long>(n));
        int count{0};
        for(int i{0};i<m;++i) {
            if(s[i] == t[0]) {
                ++count;
            }
            dp[i][0] = count;
        }
        for(int i{1};i<m;++i) {
            int mini = max(i-m+n, 1), maxi = min(i+1, n);
            for(int j{mini};j<maxi;++j) {
                if(t[j] == s[i]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp.back().back();
    }
    int solution2(string &s, string &t) {
        if(s.size() < t.size()) return 0;
        int m = s.size(), n = t.size();
        vector<long> dp(n);
        if(s[0]==t[0]) ++dp[0];
        int prev{(int)dp[0]}, ptemp;
        for(int i{1};i<m;++i) {
            int mini = max(i-m+n, 1), maxi = min(i+1, n);
            prev = dp[mini-1];
            if(s[i] == t[0]) {
                ++dp[0];
            }
            for(int j{mini};j<maxi;++j) {
                ptemp = dp[j];
                if(t[j] == s[i]) {
                    dp[j] += prev;
                }
                prev = ptemp;
            }
        }
        return dp.back();
    }
public:
    int numDistinct(string s, string t) {
        // return solution1(s, t);
        return solution2(s, t);
    }
};