class Solution {
    int solution1(string &s) {
        if(s.size() == 0) return 0;

        int ans{0}, oc{0};
        for(char ch: s) {
            if(ch == '(') ++oc;
            else if(oc == 0) ++ans;
            else --oc;
        }

        return ans+oc;
    }
public:
    int minAddToMakeValid(string s) {
        return solution1(s);
    }
};