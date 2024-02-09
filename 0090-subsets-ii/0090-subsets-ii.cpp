class Solution {
private:
    void solution1Helper(vector<int>& nums, int i, vector<vector<int>> &ans, vector<int> &curr) {
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        int j = i+1;
        solution1Helper(nums, j, ans, curr);
        while(j<nums.size() && nums[i] == nums[j]) curr.push_back(nums[i]), ++j;
        curr.push_back(nums[i]);
        solution1Helper(nums, j, ans, curr);
        curr.pop_back();
        --j;
        while(j>i && nums[i] == nums[j]) curr.pop_back(), --j;
    }
    vector<vector<int>> solution1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solution1Helper(nums, 0, ans, curr);
        return ans;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        return solution1(nums);
    }
};