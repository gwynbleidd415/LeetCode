class Solution {
public:
    double myPow(double x, int n) {
        double res{1};
        if(n<0) {
            x = 1/x;
            if(n == INT_MIN){
                n = INT_MAX;
                res = x;
            } else {
                n = -n;
            }
        }
        while(n){
            if(n&1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};