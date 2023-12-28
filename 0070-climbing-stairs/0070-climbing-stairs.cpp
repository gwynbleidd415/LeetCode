class Solution {
public:
    int climbStairs(int n) {
        int l0{1}, l1{1};
        for(int i{1};i<n;++i){
            l1 = l0 + l1;
            l0 = l1 - l0;
        }
        return l1;
    }
};