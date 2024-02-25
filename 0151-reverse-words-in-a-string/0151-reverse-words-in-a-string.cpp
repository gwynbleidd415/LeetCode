class Solution {
private:
    string solution1(string &s) {
        istringstream iss(s);
        string ans{""}, temp;
        while(getline(iss, ans, ' ') && ans == "") {};
        while(getline(iss, temp, ' ')) {
            if(temp == "") continue;
            ans = temp + " " + ans;
        }
        return ans;
    }
    string solution2(string &s) {
        int i{0}, n = s.size();
        while(i<n && s[i] == ' ') ++i;
        if(i == n) return "";
        string ans{""};
        while(true) {
            while(i<n && s[i] == ' ') ++i;
            if(i>=n) break;
            int j{i+1};
            while(j<n && s[j] != ' ') ++j;
            ans = s.substr(i, j-i) + (ans == "" ? "" : " ") + ans;
            i = j+1;
        }
        return ans;
    }
public:
    string reverseWords(string s) {
        // return solution1(s);
        return solution2(s);
    }
};
