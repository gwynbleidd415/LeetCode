class Solution {
    string countAndSayHelper(int n){
        if(n == 1) return "1";
        string str = countAndSayHelper(n-1);
        string ans = "";
        char curr{str[0]};
        int count{1};
        for(int i{1};i<str.size();++i){
            if(str[i] == curr){
                ++count;
                continue;
            }
            ans += to_string(count) + string(1, curr);
            curr = str[i];
            count = 1;
        }
        ans += to_string(count) + string(1, curr);
        return ans;
    }
public:
    string countAndSay(int n) {
        return countAndSayHelper(n);
    }
};