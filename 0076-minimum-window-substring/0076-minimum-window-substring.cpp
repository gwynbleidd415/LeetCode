class Solution {
public:
    string minWindow(string s, string t) {
        int m{(int)s.size()}, n{(int)t.size()};
        vector<int> charr(128, 0);
        int toPos{0};
        for(char ch:t) if(++charr[ch] == 1) ++toPos;
        int l{0}, r{0};
        int al{0}, len{INT_MAX};
        while(r<m){
            if(--charr[s[r++]] == 0) --toPos;
            if(toPos) continue;
            while(toPos == 0){
                if(++charr[s[l++]] == 1) ++toPos;
            }
            if(r-l+1 < len) {
                al = l-1;
                len = r-l+1;
            }
        }
        if(len == INT_MAX) return "";
        return s.substr(al, len);

        // int m{(int)s.size()}, n{(int)t.size()};
        // vector<int> charr(128, 0);
        // vector<bool> ccharr(128, 0);
        // int toPos{0};
        // for(char ch:t){
        //     ++charr[ch];
        // }
        // for(int i{0};i<128;++i){
        //     if(charr[i]) ccharr[i] = true, ++toPos;
        // }
        // int l{0}, r{0};
        // int al{0}, len{INT_MAX};
        // while(r<m){
        //     if(ccharr[s[r]]){
        //         if(--charr[s[r]] == 0) --toPos;
        //     }
        //     ++r;
        //     if(toPos) {
        //         continue;
        //     }
        //     while(toPos == 0){
        //         if(ccharr[s[l]]){
        //             if(++charr[s[l]] == 1) ++toPos;
        //         }
        //         ++l;
        //     }
        //     if(r-l+1 < len) {
        //         al = l-1;
        //         len = r-l+1;
        //     }
        // }
        // if(len == INT_MAX) return "";
        // return s.substr(al, len);
    }
};