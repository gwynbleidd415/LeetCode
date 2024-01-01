class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool isNeg = false;
        while(i < s.size() && s[i] == ' ') ++i;
        if(i == s.size()) return 0;
        if(s[i] == '-'){
            isNeg = true;
            ++i;
        } else if(s[i] == '+'){ ++i; }
        while(i < s.size() && s[i] == '0') ++i;
        if(i == s.size() || s[i] > '9' || s[i] < '0') return 0;
        int j = i;
        while(j < s.size() && s[j] >= '0' && s[j] <= '9'){ ++j; }
        string num = s.substr(i, j-i);
        string minNeg = to_string(INT_MIN).substr(1);
        string posMax = to_string(INT_MAX);
        if(isNeg){
            if(minNeg.size() < num.size() || (minNeg.size() == num.size() && minNeg <= num)) return INT_MIN;
        } else {
            if(posMax.size() < num.size() || (posMax.size() == num.size() && posMax <= num)) return INT_MAX;
        }
        int ans = 0;
        for(auto &ch: num){
            ans = ans*10 + (ch - '0');
        }
        return isNeg ? -ans : ans;
    }
};