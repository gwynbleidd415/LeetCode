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
public:
    bool isInterleave(string s1, string s2, string s3) {
        return solution1(s1, s2, s3);
    }
};