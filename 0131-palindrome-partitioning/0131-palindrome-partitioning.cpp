class Solution {
private:
    bool isPalindrome(string &s, int str, int end) {
        while(str < end) {
            if(s[str] != s[end]) return false;
            ++str, --end;
        }
        return true;
    }
    void solution1Helper(string &s, int str, vector<string> &curr, vector<vector<string>> &ans) {
        if(str == s.size()) {
            ans.push_back(curr);
            return;
        }
        for(int end{str};end<s.size();++end) {
            if(isPalindrome(s, str, end)) {
                curr.push_back(s.substr(str, end-str+1));
                solution1Helper(s, end+1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> solution1(string &s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solution1Helper(s, 0, curr, ans);
        return ans;
    }
public:
    vector<vector<string>> partition(string s) {
        return solution1(s);
    }
};