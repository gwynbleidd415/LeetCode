class Solution {
private:
    string solution1(string &a, string &b) {
        if(a.size() < b.size()) return solution1(b, a);
        int i = a.size()-1, j = b.size() - 1;
        string ans(a.size(), '0');
        bool carry{false};
        bool cd, sd;
        while(j>=0) {
            cd = sd = false;
            if(a[i] == '1') sd = true;
            if(b[j] == '1') {
                if(sd) cd = true, sd = false;
                else sd = true;
            }
            if(carry) {
                if(sd) cd = true, sd = false;
                else sd = true;
            } 
            ans[i] = sd ? '1' : '0';
            carry = cd;
            --i, --j;
        }
        while(i>=0 && carry) {
            if(a[i] != '1') {
                carry = false;
                ans[i] = '1';
            }
            --i;
        }
        while(i>=0) {
            ans[i] = a[i];
            --i;
        }
        if(carry) ans.insert(0, 1, '1');
        return ans;
    }
public:
    string addBinary(string a, string b) {
        return solution1(a, b);
    }
};