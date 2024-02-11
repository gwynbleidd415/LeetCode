class Solution {
private:
    bool solution1Helper(int index, int summ, int totSum, vector<vector<int>> &dp, vector<int> &nums) {
        if(summ == totSum-summ) return true;
        if(index == nums.size()) return false;
        if(dp[index][summ] != -1) return dp[index][summ] == 1;
        dp[index][summ] = solution1Helper(index+1, summ+nums[index], totSum, dp, nums);
        if(dp[index][summ]) return true;
        return dp[index][summ] = solution1Helper(index+1, summ, totSum, dp, nums);
    }
    bool solution1(vector<int>& nums) {
        int n = nums.size(), totSum{0};
        for(int num: nums) totSum += num;
        vector<vector<int>> dp(n, vector<int>(totSum+1, -1));
        return solution1Helper(0, 0, totSum, dp, nums);
    }
    bool solution2(vector<int>& nums) {
        int n = nums.size(), totSum{0};
        for(int num: nums) totSum += num;
        if(totSum & 1) return false;
        int halfSum{totSum>>1};
        vector<bool> dp(halfSum + 1, false);
        dp[0] = true;
        for(int i{0};i<n;++i) {
            for(int j{halfSum};j>=nums[i];--j) {
                if(dp[j]) continue;
                dp[j] = dp[j-nums[i]];
            }
        }
        return dp.back();
    }
public:
    bool canPartition(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};