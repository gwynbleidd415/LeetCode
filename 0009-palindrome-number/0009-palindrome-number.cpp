class Solution {
private:
    bool solution1(int x){
        if(x < 0) return false;
        long rev{0}, copy{x};
        while(x) {
            rev = rev*10 + x%10;
            x/=10;
        }
        return rev == copy;
    }
public:
    bool isPalindrome(int x) {
        return solution1(x);
    }
};