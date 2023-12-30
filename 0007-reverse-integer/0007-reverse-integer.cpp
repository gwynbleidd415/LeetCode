class Solution {
private:
    // const string negMin = "-2147483648";
    // const string posMax = "2147483647";
public:
    int reverse(int x) {
        // string xs = to_string(x);
        // auto startItr = xs.begin();
        // if(x < 0) startItr += 1;
        // std::reverse(startItr, xs.end());
        // if(x > 0){
        //     if(posMax.size() < xs.size() || (posMax.size() == xs.size() && posMax < xs)){
        //         return 0;
        //     }
        // } else if(x < 0) {
        //     if(negMin.size() < xs.size() || (negMin.size() == xs.size() && negMin < xs)){
        //         return 0;
        //     }
        // }
        // return stoi(xs);

        int rev = 0, pop;
        while(x) {
            pop = x % 10;
            x /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};