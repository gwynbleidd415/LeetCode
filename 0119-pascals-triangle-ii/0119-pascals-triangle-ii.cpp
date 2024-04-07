class Solution {
private:
    vector<int> solution1(int rowIndex) {
        vector<int> curr{1};
        for(int i{0};i<rowIndex;++i) {
            vector<int> ncurr(i+2);
            ncurr.front() = ncurr.back() = 1;
            for(int j{0};j<i;++j) {
                ncurr[j+1] = curr[j] + curr[j+1];
            }
            curr = ncurr;
        }
        return curr;
    }
    vector<int> solution2(int rowIndex) {
        vector<int> ans(rowIndex+1);
        ans.front() = 1;
        for(int i{0};i<rowIndex;++i) {
            ans[i+1] = 1;
            for(int j{i};j>0;--j) {
                ans[j] += ans[j-1];
            }
        }
        return ans;
    }
public:
    vector<int> getRow(int rowIndex) {
        // return solution1(rowIndex);
        return solution2(rowIndex);
    }
};