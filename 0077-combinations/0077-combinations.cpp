class Solution {
private:
    void solution1Helper(int i, int ci, int n, int k, vector<int> &current, vector<vector<int>> &ans) {
        if(i == k) {
            ans.push_back(current);
            return;
        }
        for(int j{ci+1};n-j+1>=k-i;++j) {
            current[i] = j;
            solution1Helper(i+1, j, n, k, current, ans);
        }
    }
    vector<vector<int>> solution1(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current(k);
        solution1Helper(0, 0, n, k, current, ans);
        return ans;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        return solution1(n, k);
    }
};