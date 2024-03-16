class Solution {
private:
    void solution1Helper(int count, int i, string curr, vector<string> &ans, string &s) {
        if(count == 4) {
            if(i == s.size()) {
                ans.push_back(curr);
            }
            return;
        }
        if(i == s.size()) return;
        ++count;
        if(curr!="") curr.push_back('.');
        solution1Helper(count, i+1, curr+s.substr(i, 1), ans, s);
        if(s[i] == '0' || i+1 == s.size()) return;
        solution1Helper(count, i+2, curr+s.substr(i, 2), ans, s);
        if(i+2 == s.size()) return;
        string str = s.substr(i, 3);
        if(str > "255") return;
        solution1Helper(count, i+3, curr+str, ans, s);
    }
    vector<string> solution1(string &s) {
        vector<string> ans;
        solution1Helper(0, 0, "", ans, s);
        return ans;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        return solution1(s);
    }
};