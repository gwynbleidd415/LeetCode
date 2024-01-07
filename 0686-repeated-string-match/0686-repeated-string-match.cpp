class Solution {
private:
    static const long MOD = 1e9 + 7, MULT = 31;
    bool doesMatch(string &a, string &b, int si, int ei){
        for(int i{0};i<ei;++i, ++si){
            if(si == a.size()) si = 0;
            if(a[si] != b[i]) return false;
        }
        return true;
    }
    int rabinKarpMethod(string &a, string &b) {
        int i{0}, j{0};
        long hashA{0}, hashB{0}, maxPow{0};
        int si{-1};
        while(j<b.size()) {
            if(i == a.size()) i = 0;
            if(a[i] == b[j]) {
                hashA = ((hashA*MULT)%MOD + (a[i]-'a'))%MOD;
                hashB = ((hashB*MULT)%MOD + (b[j]-'a'))%MOD;
                if(maxPow) maxPow = (maxPow * MULT)%MOD;
                else maxPow = 1;
                if(si == -1) si = i;
                ++i, ++j;
            } else if (j == 0) {
                ++i;
                if(i==a.size()) return -1;
            } else {
                do {
                    hashA = (MOD + hashA - (maxPow*(a[si]-'a'))%MOD)%MOD;
                    hashA = ((hashA*MULT)%MOD + (a[i]-'a'))%MOD;
                    ++si, ++i;
                    cout << si << ' ' << hashA << ' ' << hashB << '\n';
                    if(si == a.size()) return -1;
                    if(i == a.size()) i = 0;
                } while(hashA!=hashB || !doesMatch(a, b, si, j));
            }
        }
        return (si + b.size())/a.size() + ((si+b.size())%a.size() == 0 ? 0 : 1);
    }
    int rabinKarpMethod2(string &a, string &b) {
        long hashB{b[0] - 'a'}, hashA{a[0] - 'a'}, maxPow{1};
        int ei{1}, si{0};
        for(int i{1};i<b.size();++i, ++ei) {
            if(ei == a.size()) ei = 0;
            hashB = ((hashB*MULT)%MOD + (b[i]-'a'))%MOD;
            hashA = ((hashA*MULT)%MOD + (a[ei]-'a'))%MOD;
            maxPow = (maxPow*MULT)%MOD;
        }
        while(hashA != hashB || !doesMatch(a, b, si, b.size())) {
            if(ei == a.size()) ei = 0;
            hashA = (MOD + hashA - (maxPow*(a[si]-'a'))%MOD)%MOD;
            hashA = ((hashA*MULT)%MOD + (a[ei]-'a'))%MOD;
            ++si, ++ei;
            if(si == a.size()) return -1;
        }
        return (si + b.size())/a.size() + ((si+b.size())%a.size() == 0 ? 0 : 1); 
    }
public:
    int repeatedStringMatch(string a, string b) {
        // return rabinKarpMethod(a, b);
        return rabinKarpMethod2(a, b);
    }
};