class Solution {
private:
    bool solution1Helper(string &s1, string &s2, int str1, int end1, int str2, int end2, vector<vector<vector<vector<bool>>>> &dp, vector<vector<vector<vector<bool>>>> &vis) {
        if(str1 == end1) return s1[str1] == s2[str2];
        if(vis[str1][end1][str2][end2]) return dp[str1][end1][str2][end2];
        vis[str1][end1][str2][end2] = true;
        vector<int> c1(26), c2(26);
        int diff{0}, i1{0}, i2{0}, i3{0}, i4{}, diff1{0};
        for(int i{str1}, j{str2};i<=end1;++i,++j) {
            i1 = s1[i]-'a', i2 = s2[j]-'a';
            if(c1[i1] == c2[i1]) ++diff;
            if(c1[i2] == c2[i2]) ++diff;
            ++c1[i1], ++c2[i2];
            if(c1[i1] == c2[i1]) --diff;
            if(c1[i2] == c2[i2]) --diff;
        }
        if(diff) return false;
        vector<int> c3(c1.begin(), c1.end());
        for(int i{str1}, j{str2};i<end1;++i,++j) {
            i4 = end2-(j-str2);
            i1 = s1[i]-'a', i2 = s2[j]-'a', i3 = s2[i4]-'a';
            if(c1[i1] == c2[i1]) ++diff;
            if(c1[i2] == c2[i2]) ++diff;
            if(c1[i1] == c3[i1]) ++diff1;
            if(c1[i3] == c3[i3]) ++diff1;
            --c1[i1], --c2[i2], --c3[i3];
            if(c1[i1] == c2[i1]) --diff;
            if(c1[i2] == c2[i2]) --diff;
            if(c1[i1] == c3[i1]) --diff1;
            if(c1[i3] == c3[i3]) --diff1;
            if(diff == 0) {
                if(solution1Helper(s1, s2, str1, i, str2, j, dp, vis) && solution1Helper(s1, s2, i+1, end1, j+1, end2, dp, vis)) {
                    dp[str1][end1][str2][end2] = true;
                    return true;
                }
            }
            if(diff1 == 0) {
                if(solution1Helper(s1, s2, str1, i, i4, end2, dp, vis) && solution1Helper(s1, s2, i+1, end1, str2, i4-1, dp, vis)) {
                    dp[str1][end1][str2][end2] = true;
                    return true;
                }
            }
        }
        return false;
    }
    bool solution1(string &s1, string &s2) {
        int n = s1.size();
        vector<vector<vector<vector<bool>>>> dp(n, vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n))));
        vector<vector<vector<vector<bool>>>> vis(n, vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n))));
        return solution1Helper(s1, s2, 0, n-1, 0, n-1, dp, vis);
    }
public:
    bool isScramble(string s1, string s2) {
        return solution1(s1, s2);
    }
};