class Solution {
private:
    void swapVector(vector<int> &digits){
        int i{0}, j{(int)digits.size()-1};
        while(j > i) {
            swap(digits[i++], digits[j--]);
        }
    }
public:
    vector<int> plusOne(vector<int>& digits) {
        swapVector(digits);
        int carry{1}, n{(int)digits.size()};
        for(int i{0};i<n;++i){
            digits[i] = digits[i] + carry;
            if(digits[i] == 10){
                digits[i] = 0;
            } else break;
        }
        if(digits.back() == 0) digits.push_back(1);
        swapVector(digits);
        return digits;
    }
};