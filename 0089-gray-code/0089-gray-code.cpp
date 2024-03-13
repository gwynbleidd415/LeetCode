class Solution {
private:
    vector<int> solution1(int n) {
        vector<int> ans{0,1};
        int ci = 2;
        for(int i{1};i<n;++i) {
            for(int j = ans.size() - 1;j>=0;--j) ans.push_back(ans[j]|ci);
            ci <<= 1;
        }
        return ans;
    }
public:
    vector<int> grayCode(int n) {
        return solution1(n);
    }
};