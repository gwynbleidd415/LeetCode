class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {""};
        vector<string> inner, outer, ans;
        for(int i{0};i<n;++i){
            inner = generateParenthesis(i);
            outer = generateParenthesis(n-i-1);
            for(string &str: inner){
                for(string &str1: outer){
                    ans.push_back("(" + str + ")" + str1);
                }
            }
        }
        return ans;
    }
};