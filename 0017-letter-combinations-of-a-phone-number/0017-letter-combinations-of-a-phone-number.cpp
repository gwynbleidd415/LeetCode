class Solution {
private:
    // static const vector<string> map;
    inline static const vector<string> map{"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    // void letterCombinationsHelper(string &digits, string &currStr, vector<string> &ans, int pos){
    //     if(pos == digits.size()) {
    //         ans.push_back(currStr);
    //         return;
    //     };
        
    //     for(char ch: map[digits[pos] - '0']){
    //         currStr.push_back(ch);
    //         letterCombinationsHelper(digits, currStr, ans, pos+1);
    //         currStr.pop_back();
    //     }
    // }
public:
    vector<string> letterCombinations(string digits) {
        // vector<string> ans;
        // if(!digits.size()) return ans;
        // string currStr = "";
        // letterCombinationsHelper(digits, currStr, ans, 0);
        // return ans;

        if(!digits.size()) return {};
        
        vector<string> ans{""};
        for(char ch: digits){
            vector<string> curr;
            for(char ch1: map[ch-'0']){
                for(string &str: ans){
                    curr.push_back(str + string(1, ch1));
                }
            }
            ans = curr;
        }
        return ans;
    }
};
// const vector<string> Solution::map{"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
