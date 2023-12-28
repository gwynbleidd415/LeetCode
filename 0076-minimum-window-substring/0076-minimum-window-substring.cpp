class Solution {
public:
    string minWindow(string s, string t) {
        int m{(int)s.size()}, n{(int)t.size()};
        vector<int> charr(128, 0);
        vector<bool> ccharr(128, 0);
        int toPos{0};
        for(char ch:t){
            ++charr[ch];
        }
        for(int i{0};i<128;++i){
            if(charr[i]) ccharr[i] = true, ++toPos;
        }
        int l{0}, r{0};
        int al{0}, len{INT_MAX};
        while(r<m){
            if(ccharr[s[r]]){
                --charr[s[r]];
                if(charr[s[r]] == 0) --toPos;
            }
            ++r;
            if(toPos) {
                continue;
            }
            // cout << r << ' ';
            while(l < r && toPos == 0){
                if(ccharr[s[l]]){
                    if(charr[s[l]] == 0) ++toPos;
                    ++charr[s[l]];
                }
                ++l;
            }
            // cout << l << '\n';
            if(r-l+1 < len) {
                al = l-1;
                len = r-l+1;
            }
        }
        if(len == INT_MAX) return "";
        return s.substr(al, len);
    }
};