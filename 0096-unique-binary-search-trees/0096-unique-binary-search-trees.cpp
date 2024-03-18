class Solution {
private:
    int solution1(int n) {
        if(n<=2) return n;
        long ans{1};
        for(int i{1};i<=n;++i) {
            ans *= i+n;
            ans /= i;
        }
        ans /= n+1;
        return ans;
    }
public:
    int numTrees(int n) {
        return solution1(n);
    }
};