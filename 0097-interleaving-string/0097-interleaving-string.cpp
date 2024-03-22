class Solution {
private:
    bool solution1Helper(string &s1, string &s2, string &s3, int start1, int start2, vector<vector<bool>> &dp, vector<vector<bool>> &visited) {
        if(start1 == s1.size() && start2 == s2.size()) return true;
        if(visited[start1][start2]) return dp[start1][start2];
        visited[start1][start2] = true;
        int start3 = start1+start2;
        if(start1 < s1.size() && s3[start3] == s1[start1] && solution1Helper(s1, s2, s3, start1+1, start2, dp, visited)) dp[start1][start2] = true;
        else if(start2 < s2.size() && s3[start3] == s2[start2] && solution1Helper(s1, s2, s3, start1, start2+1, dp, visited)) dp[start1][start2] = true;
        return dp[start1][start2];
    }
    bool solution1(string &s1, string &s2, string &s3) {
        if(s3.size()!= s1.size() + s2.size()) return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1));
        vector<vector<bool>> visited(s1.size()+1, vector<bool>(s2.size()+1));
        return solution1Helper(s1, s2, s3, 0, 0, dp, visited);
    }
    bool solution2(string &s1, string &s2, string &s3) {
        if(s3.size()!= s1.size() + s2.size()) return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1));
        dp.front().front() = true;
        for(int i{0};i<s1.size();++i) {
            dp[i+1][0] = (s1[i] == s3[i] && dp[i][0]);
        }
        for(int i{0};i<s2.size();++i) {
            dp[0][i+1] = (s2[i] == s3[i] && dp[0][i]);
        }
        for(int i{0};i<s1.size();++i) {
            for(int j{0};j<s2.size();++j) {
                if(s3[i+j+1] == s1[i] && dp[i][j+1]) dp[i+1][j+1] = true;
                else if(s3[i+j+1] == s2[j] && dp[i+1][j]) dp[i+1][j+1] = true;
            }
        }
        return dp.back().back();
    }
    bool solution3(string &s1, string &s2, string &s3) {
        if(s3.size()!= s1.size() + s2.size()) return false;
        vector<bool> dp(s2.size()+1);
        dp.front() = true;
        for(int i{0};i<s2.size();++i) {
            dp[i+1] = s2[i] == s3[i] && dp[i];
        }
        for(int i{0};i<s1.size();++i) {
            if(dp[0] && s3[i]!=s1[i]) dp[0] = false; 
            for(int j{0};j<s2.size();++j) {
                if(s3[i+j+1] == s1[i] && dp[j+1]) continue;
                else if(s3[i+j+1] == s2[j] && dp[j]) dp[j+1] = true;
            }
        }
        return dp.back();
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // return solution1(s1, s2, s3);
        // return solution2(s1, s2, s3);
        return solution3(s1, s2, s3);
    }
};