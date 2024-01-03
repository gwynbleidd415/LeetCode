class Solution {
private:
    vector<string> constructStringVector(vector<int> &qs){
        int n = qs.size();
        string str;
        vector<string> ans;
        for(int i{0};i<n;++i) {
            ans.push_back(string(qs[i], '.') + "Q" + string(n-qs[i]-1, '.'));
        }
        return move(ans);
    }
    void solveNQueensHelper(int n, int i, vector<int> &qs, vector<vector<string>> &ans) {
        if(i == n) {
            ans.push_back(constructStringVector(qs));
            return;
        }
        bool isValid;
        int sum, diff;
        for(int j{0};j<n;++j) {
            isValid = true;
            sum = i+j, diff = i-j;
            for(int k{0};k<i;++k) {
                if(qs[k] == j || qs[k] + k == sum || k - qs[k] == diff) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) {
                qs[i] = j;
                solveNQueensHelper(n, i+1, qs, ans);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> qs(n);
        solveNQueensHelper(n, 0, qs, ans);
        return ans;
    }
};