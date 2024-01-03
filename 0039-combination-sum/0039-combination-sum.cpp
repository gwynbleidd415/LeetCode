class Solution {
private:
    void combinationSumHelper(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &selected, int target, int i){
        if(target == 0) {
            ans.push_back(selected);
            return;
        }
        if(i == candidates.size() || target < 0) return;
        combinationSumHelper(candidates, ans, selected, target, i+1);
        selected.push_back(candidates[i]);
        combinationSumHelper(candidates, ans, selected, target-candidates[i], i);
        selected.pop_back();
    }
    void combinationSumHelper2(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &selected, int target, int i) {
        if(target == 0) {
            ans.push_back(selected);
            return;
        }
        if(i == candidates.size() || candidates[i] > target) return;
        combinationSumHelper2(candidates, ans, selected, target, i+1);
        selected.push_back(candidates[i]);
        combinationSumHelper2(candidates, ans, selected, target-candidates[i], i);
        selected.pop_back();
    }
    void combinationSumHelper3(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &selected, int target, int i) {
        if(target == 0) {
            ans.push_back(selected);
            return;
        }
        for(int j{i};j<candidates.size() && candidates[j] <= target;++j) {
            selected.push_back(candidates[j]);
            combinationSumHelper3(candidates, ans, selected, target - candidates[j], j);
            selected.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // int n = candidates.size();
        // vector<vector<int>> ans;
        // vector<int> selected;
        // combinationSumHelper(candidates, ans, selected, target, 0);
        // return ans;

        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> selected;
        // combinationSumHelper2(candidates, ans, selected, target, 0);
        combinationSumHelper3(candidates, ans, selected, target, 0);
        return ans;
    }
};