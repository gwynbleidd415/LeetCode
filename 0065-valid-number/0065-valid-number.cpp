class Solution {
private:
    bool solution1(string &s) {
        bool intBef{false}, intAf{false};
        int n = s.size(), i{0};
        if(s[i] == '+' || s[i] == '-') ++i;
        if(i == n) return false;
        while(i<n && s[i]!='.' && s[i]!='e' && s[i]!='E') {
            if(s[i] < '0' || s[i] > '9') return false;
            ++i;
        }
        if(i>0 && s[i-1]>='0' && s[i-1]<='9') intBef = true;
        if(s[i] == '.') {
            ++i;
            while(i<n && s[i] != 'e' && s[i]!='E') {
                if(s[i] < '0' || s[i] > '9') return false;
                ++i;
            }
            if(s[i-1]>='0' && s[i-1]<='9') intAf = true;
        }
        if(!intBef && !intAf) return false;
        if(s[i] == 'e' || s[i] == 'E') {
            ++i;
            if(i == n) return false;
            if(s[i] == '+' || s[i] == '-') ++i;
            while(i<n) {
                if(s[i] < '0' || s[i] > '9') return false;
                ++i;
            }
            if(s[i-1]<'0' || s[i-1]>'9') return false;
        }
        return true;
    }
public:
    bool isNumber(string s) {
        return solution1(s);
    }
};