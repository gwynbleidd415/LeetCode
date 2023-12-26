class Solution {
private:
    inline static const vector<string> map{"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void letterCombinationsHelper(string &digits, string &currStr, vector<string> &ans, int pos){
        if(pos == digits.size()) {
            ans.push_back(currStr);
            return;
        };
        
        for(char ch: map[digits[pos] - '0']){
            currStr.push_back(ch);
            letterCombinationsHelper(digits, currStr, ans, pos+1);
            currStr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.size()) return ans;
        string currStr = "";
        letterCombinationsHelper(digits, currStr, ans, 0);
        return ans;
    }
};