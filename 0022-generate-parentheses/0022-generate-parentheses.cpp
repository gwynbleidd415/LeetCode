class Solution {
private:
    // vector<string> generateParenthesisHelper(int n, vector<vector<string>> &dp, vector<bool> &visited) {
    //     if(visited[n]) return dp[n];
    //     vector<string> inner, outer, ans;
    //     for(int i{0};i<n;++i){
    //         inner = generateParenthesisHelper(i, dp, visited);
    //         outer = generateParenthesisHelper(n-i-1, dp, visited);
    //         for(string &str: inner){
    //             for(string &str1: outer){
    //                 ans.push_back("(" + str + ")" + str1);
    //             }
    //         }
    //     }
    //     visited[n] = true;
    //     return dp[n] = ans;
    // }

    void generateParenthesisHelper2(int l, int r, string &&str, vector<string> &ans){
        if(l == 0 && r == 0){
            ans.push_back(str);
            return;
        }
        if(l>0){
            str.push_back('(');
            generateParenthesisHelper2(l-1, r, move(str), ans);
            str.pop_back();
        }
        if(l<r){
            str.push_back(')');
            generateParenthesisHelper2(l, r-1, move(str), ans);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // if(n == 0) return {""};
        // vector<string> inner, outer, ans;
        // for(int i{0};i<n;++i){
        //     inner = generateParenthesis(i);
        //     outer = generateParenthesis(n-i-1);
        //     for(string &str: inner){
        //         for(string &str1: outer){
        //             ans.push_back("(" + str + ")" + str1);
        //         }
        //     }
        // }
        // return ans;

        // vector<vector<string>> dp(n+1);
        // vector<bool> visited(n+1, false);
        // dp[0] = {""}, visited[0] = true;
        // return generateParenthesisHelper(n, dp, visited);

        vector<string> ans;
        string str = "";
        generateParenthesisHelper2(n, n, move(str), ans);
        return ans;
    }
};