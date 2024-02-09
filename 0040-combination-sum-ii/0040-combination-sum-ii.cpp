class Solution {
private:
    void solution1Helper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &curr, int ind) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(ind == candidates.size() || candidates[ind] > target) return;
        int j = ind+1;
        solution1Helper(candidates, target, ans, curr, j);
        while(j<candidates.size() && candidates[j] == candidates[ind]) curr.push_back(candidates[j++]), target -= candidates[ind];
        curr.push_back(candidates[ind]), target -= candidates[ind];
        solution1Helper(candidates, target, ans, curr, j);
        curr.pop_back(), --j;
        while(j>ind && candidates[j] == candidates[ind]) curr.pop_back(), --j;
    }
    vector<vector<int>> solution1(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        solution1Helper(candidates, target, ans, curr, 0);
        return ans;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return solution1(candidates, target);
    }
};