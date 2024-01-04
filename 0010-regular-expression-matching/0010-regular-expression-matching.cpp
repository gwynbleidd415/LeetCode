class Solution {
private:
    // bool isMatchHelper(string &s, string &p, vector<vector<bool>> &dp, vector<vector<bool>> &visited, int si, int pi){
    //     if(si == s.size() && pi == p.size()) return true;
    //     if(pi == p.size()) return false;
    //     if(visited[si][pi]) return dp[si][pi];

    //     bool ans;

    //     if(pi+1 < p.size() && p[pi+1] == '*'){
    //         if(si == s.size()){
    //             ans = isMatchHelper(s, p, dp, visited, si, pi+2);
    //             visited[si][pi] = true, dp[si][pi] = ans;
    //             return ans;
    //         }
    //         if(s[si] == p[pi] || p[pi] == '.'){
    //             ans = isMatchHelper(s, p, dp, visited, si+1, pi) || isMatchHelper(s, p, dp, visited, si, pi+2);
    //             visited[si][pi] = true, dp[si][pi] = ans;
    //             return ans;
    //         }
    //         ans = isMatchHelper(s, p, dp, visited, si, pi+2);
    //         visited[si][pi] = true, dp[si][pi] = ans;
    //         return ans;
    //     }

    //     if(si == s.size()) return false;

    //     if(s[si] == p[pi] || p[pi] == '.'){
    //         ans = isMatchHelper(s, p, dp, visited, si+1, pi+1);
    //         visited[si][pi] = true, dp[si][pi] = ans;
    //         return ans;
    //     }

    //     ans = false;
    //     visited[si][pi] = true, dp[si][pi] = ans;
    //     return ans;
    // }

    bool isMatchHelper(string &s, string &p, vector<vector<bool>> &visited, int si, int pi){
        if(si == s.size() && pi == p.size()) return true;
        if(pi == p.size()) return false;
        if(visited[si][pi]) return false;

        if(pi+1 < p.size() && p[pi+1] == '*'){
            if(si == s.size()){
                visited[si][pi] = true;
                return isMatchHelper(s, p, visited, si, pi+2);
            }
            if(s[si] == p[pi] || p[pi] == '.'){
                visited[si][pi] = true;
                return isMatchHelper(s, p, visited, si+1, pi) || isMatchHelper(s, p, visited, si, pi+2);
            }
            visited[si][pi] = true;
            return isMatchHelper(s, p, visited, si, pi+2);
        }

        if(si == s.size()) {
            visited[si][pi] = true;
            return false;
        }

        if(s[si] == p[pi] || p[pi] == '.'){
            visited[si][pi] = true;
            return isMatchHelper(s, p, visited, si+1, pi+1);
        }

        visited[si][pi] = true;
        return false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> visited(s.size()+1, vector<bool>(p.size() + 1));
        return isMatchHelper(s, p, visited, 0, 0);
    }
};
