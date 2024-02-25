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
public:
    string reverseWords(string s) {
        return solution1(s);
    }
};
