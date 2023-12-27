class Solution {
private:
    void permuteHelper(vector<int> &nums, int index, vector<int> &curr, vector<bool> &visited, vector<vector<int>> &ans){
        if(index == nums.size()) {
            ans.push_back(curr);
            return;
        };
        for(int i{0};i<nums.size();++i){
            if(visited[i]) continue;
            curr.push_back(nums[i]);
            visited[i] = true;
            permuteHelper(nums, index+1, curr, visited, ans);
            curr.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        permuteHelper(nums, 0, curr, visited, ans);
        return ans;
    }
};