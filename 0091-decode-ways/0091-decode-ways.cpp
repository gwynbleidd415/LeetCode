class Solution {
public:
    int numDecodings(string s) {
        int n{(int)s.size()};
        int n1{1}, n2{1};
        if(s.back() == '0') n1 = 0;
        for(int i{n-2};i>=0;--i){
            if(s[i] == '0') {
                n2 = n1;
                n1 = 0;
            } else {
                if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7')){
                    n1 = n1+n2;
                    n2 = n1-n2;
                } else {
                    n2 = n1;
                }
            }
        }
        return n1;
        // int n{(int)s.size()};
        // int n1{1}, n2{1};
        // if(s.back() == '0') n1 = 0;
        // for(int i{n-2};i>=0;--i){
        //     if(s[i] == '0') {
        //         n2 = n1;
        //         n1 = 0;
        //     } else {
        //         if(s.substr(i, 2) <= "26"){
        //             n1 = n1+n2;
        //             n2 = n1-n2;
        //         } else {
        //             n2 = n1;
        //         }
        //     }
        // }
        // return n1;
    }
};