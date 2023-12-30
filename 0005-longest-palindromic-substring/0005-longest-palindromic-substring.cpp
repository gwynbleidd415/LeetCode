class Solution {
public:
    string longestPalindrome(string s) {
        // int length = s.size();
        // vector<vector<bool>> arr(length, vector<bool>(length, false));
        // int ans = 1;
        // int si=0, len=1;
        // for(int i=0;i<length-1;++i){
        //     arr[i][i] = true;
        //     if(s[i] == s[i+1]){
        //         arr[i][i+1] = true;
        //         if(len == 2) continue;
        //         si = i, len = 2;
        //     }
        // }
        // arr[length-1][length-1] = true;

        // for(int i = 2; i < length; ++i){
        //     for(int j=0;j<length-i;++j){
        //         if(s[j] == s[j+i] && arr[j+1][j+i-1]){
        //             arr[j][j+i] = true;
        //             if(len == i+1) continue;
        //             si = j, len = i+1;
        //         }
        //     }
        // }

        // return s.substr(si, len);

        // int len = 1;
        // int si = 0;
        // for(int i{0};i<s.size();){
        //     int l = i, r = i;
        //     while(r < s.size() -1 && s[r] == s[r+1]) ++r;
        //     i = r+1;
        //     while(l>=0 && r<s.size() && s[l] == s[r]){
        //         ++r, --l;
        //     }
        //     if(len < r-l-1){
        //         len = r-l-1;
        //         si = l+1;
        //     }
        // }
        // return s.substr(si, len);

        int len = 1, si = 0;
        string newS = "#";
        for(char &ch: s){
            newS = newS + ch + '#';
        }
        vector<int> palLen(newS.size());
        int i{0}, r = 1;
        while(i<palLen.size()){
            while(i-r >= 0 && i+r < newS.size() && newS[i-r] == newS[i+r]){
                ++r;
            }
            --r;
            palLen[i] = r*2+1;
            if(r > len){
                len = r;
                si = (i-r)/2;
            }
            int lenn = r, xx = 1;
            while(i-xx>=0 && i+xx < palLen.size() && palLen[i-xx]/2 + xx < lenn){
                palLen[i+xx] = palLen[i-xx];
                ++xx;
            }
            r = lenn - xx + 1;
            i = i+xx;
        }
        return s.substr(si, len);
    }
};