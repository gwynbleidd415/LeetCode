class Solution {
private:
    int solution1Helper1(vector<int> &nums, int l, int r, int lm, int rm) {
        if(l > r) return 0;
        int mult{lm * rm};
        if(l == r) return nums[l]*mult;
        int ans{0}, left, right;
        for(int i{l};i<=r;++i) {
            left = solution1Helper1(nums, l, i-1, lm, nums[i]);
            right = solution1Helper1(nums, i+1, r, nums[i], rm);
            ans = max(ans, left + right + nums[i] * mult);
        }
        return ans;
    }
    int solution1Helper2(vector<int> &nums, vector<vector<int>> &dp, int l, int r) {
        if(l > r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int mult{(l>0 ? nums[l-1] : 1) * (r+1<nums.size() ? nums[r+1] : 1)};
        if(l == r) return nums[l]*mult;
        int ans{0}, left, right;
        for(int i{l};i<=r;++i) {
            left = solution1Helper2(nums, dp, l, i-1);
            right = solution1Helper2(nums, dp, i+1, r);
            ans = max(ans, left + right + nums[i] * mult);
        }
        return dp[l][r] = ans;
    }
    int solution1(vector<int>& nums) {
        // return solution1Helper1(nums, 0, nums.size()-1, 1, 1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solution1Helper2(nums, dp, 0, nums.size()-1);
    }
public:
    int maxCoins(vector<int>& nums) {
        return solution1(nums);
    }
};