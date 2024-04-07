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
public:
    vector<int> getRow(int rowIndex) {
        return solution1(rowIndex);
    }
};