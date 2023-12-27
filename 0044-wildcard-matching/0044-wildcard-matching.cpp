class Solution {
private:
    // int isMatchHelper(string &s, string &p, int ls, int rs, int lp, int rp){
    //     int maxi = rs - rp + lp + 1;
    //     int j, k;
    //     for(int i{ls}; i < maxi; ++i){
    //         k = i, j = lp;
    //         while(j<=rp){
    //             if(p[j] != '?' && s[k] != p[j]) break;
    //             ++j, ++k;
    //         }
    //         if(j>rp) return i;
    //     }
    //     return -1;
    // }
public:
    bool isMatch(string s, string p) {
        // if(p.size() == 0) return (s.size() == 0);
        // int lp{0}, rp{(int)p.size()-1}, ls{0}, rs{(int)s.size()-1};
        // while(lp < p.size() && p[lp] == '*') ++lp;
        // if(lp == p.size()) return true;
        // if(lp == 0){
        //     int trp = lp+1;
        //     while(trp < p.size() && p[trp] != '*') ++trp;
        //     --trp;
        //     if(trp == rp && rs != rp) return false;
        //     if(rs < trp) return false;
        //     // cout << trp << ' ' << rp << ' ' << rs << '\n';
        //     if(isMatchHelper(s, p, 0, trp, 0, trp) == -1) return false;
        //     if(trp == rp) return true;
        //     lp = trp+1, ls = lp;
        // }
        // while(rp >= 0 && p[rp] == '*') --rp;
        // if(rp == p.size()-1){
        //     // cout << rp <<'\n';
        //     int tlp = rp-1;
        //     while(tlp >=0 && p[tlp] != '*') --tlp;
        //     ++tlp;
        //     int itemp = rs-(rp - tlp);
        //     if(itemp < ls) return false;
        //     if(isMatchHelper(s, p, itemp, rs, tlp, rp) == -1) return false;
        //     // cout << tlp << ' ' << rp << ' ' << rs << '\n';
        //     rs = rs - (rp-tlp) -1, rp = tlp-1;
        // }
        // // cout << ls << ' ' << rs << ' ' << lp <<' '<<rp<<'\n';
        // int tempp;
        // while(lp <= rp){
        //     while(lp <= rp && p[lp] == '*') ++lp;
        //     int trp = lp;
        //     while(trp <= rp && p[trp] != '*') ++trp;
        //     --trp;
        //     // cout << lp <<' '<<trp << ' ' << ls << ' ' << rs <<'\n';
        //     tempp = isMatchHelper(s, p, ls, rs, lp, trp);
        //     // cout << tempp <<'\n';
        //     if(tempp == -1) return false;
        //     ls = tempp + (trp - lp + 1);
        //     lp = trp + 1;
        // }
        // return true;

        int sn{(int)s.size()}, pn{(int)p.size()};
        int si{0}, pi{0};
        int starPos{-1}, tempSPos{-1};
        while(si<sn){
            if(pi < pn && (s[si] == p[pi] || p[pi] == '?')) ++si, ++pi;
            else if(pi < pn && p[pi] == '*'){
                starPos = pi++;
                tempSPos = si + 1;
            } else if(starPos == -1) return false;
            else{
                si = tempSPos;
                pi = starPos+1;
                tempSPos = si + 1;
            }
        }
        while(pi < pn){
            if(p[pi++] != '*') return false;
        }
        return true;
    }
};