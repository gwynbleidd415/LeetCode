class Solution {
private:
    bool isChar(char ch) {
        return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
    }
    int solution1(string &s) {
        int st{-1}, end{-1};
        for(int i{0};i<s.size();++i) {
            if(isChar(s[i]) && end>=st) {
                st = i;
            } else if(s[i] == ' ' && end<st) {
                end = i-1;
            }
        }
        if(isChar(s.back())) return s.size() - st;
        return end-st+1;
    }
public:
    int lengthOfLastWord(string s) {
        return solution1(s);
    }
};