class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        long long int j{2};
        for(;j*j<=x;++j);
        return j-1;
    }
};