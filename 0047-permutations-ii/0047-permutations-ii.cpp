class Solution {
private:
    void solution1Helper(int n, vector<int> &nums, vector<int> &cPer, vector<vector<int>> &ans, vector<bool> &picked) {
        if(n == nums.size()) {
            ans.push_back(cPer);
            return;
        }
        for(int i{0};i<nums.size();++i) {
            if(picked[i]) continue;
            if(i>0 && nums[i-1]==nums[i] && !picked[i-1]) continue;
            picked[i] = true;
            cPer[n] = nums[i];
            solution1Helper(n+1, nums, cPer, ans, picked);
            picked[i] = false;
        }
    }
    vector<vector<int>> solution1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> picked(nums.size());
        vector<int> cPer(nums.size());
        vector<vector<int>> ans;
        solution1Helper(0, nums, cPer, ans, picked);
        return ans;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return solution1(nums);
    }
};