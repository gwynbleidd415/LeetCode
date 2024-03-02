class Solution {
private:
    void addString(string &str1, string &str2) {
        if(str2.size() > str1.size()) swap(str1, str2);
        if(str2 == "") return;
        int carry = 0;
        int i = str1.size()-1, j = str2.size()-1;
        int summ;
        while(j>=0) {
            summ = (str1[i]-'0') + (str2[j] - '0') + carry;
            carry = summ / 10;
            str1[i] = char(summ - carry*10 + '0');
            --j, --i;
        }
        while(i>=0 && carry) {
            summ = (str1[i] - '0') + carry;
            carry = summ / 10;
            str1[i] = char(summ - carry*10 + '0');
            --i;
        }
        if(carry) str1.insert(0, 1, char(carry + '0'));
    }
    string solution1(string &num1, string &num2) {
        if(num1 == "0" || num2 == "0") return "0";
        string mans{""};
        int n1 = num1.size(), n2 = num2.size();
        for(int i{n2-1};i>=0;--i) {
            string carry{""}, ans{""};
            int cd = num2[i] - '0';
            for(int j{n1-1};j>=0;--j) {
                string str = to_string((int)(num1[j]-'0') * cd);
                addString(carry, str);
                ans.push_back(carry.back());
                carry.pop_back();
            }
            reverse(ans.begin(), ans.end());
            ans = carry + ans;
            for(int j{i+1};j<n2;++j) ans.push_back('0');
            addString(mans, ans);
            // cout << ans << ' ' << mans << '\n';
        }
        return mans;
    }
    string solution2(string &num1, string &num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size(), n2 = num2.size(), tn{n1+n2-1};
        string ans(n1+n2, '0');
        int mult, tnij;
        for(int i{n1-1};i>=0;--i) {
            for(int j{n2-1};j>=0;--j) {
                tnij = tn - i - j - 1;
                mult = (num1[i] - '0') * (num2[j] - '0') + (ans[tnij]-'0');
                ans[tnij] = mult%10 + '0';
                ans[tnij+1] += mult/10;
            }
        }
        if(ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        // return solution1(num1, num2);
        return solution2(num1, num2);
    }
};