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
    int solution2(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int mult, ei, ans;
        dp.front().front() = nums.front() * (n>1 ? nums[1] : 1);
        dp.back().back() = nums.back() * (n>1 ? nums[n-2] : 1);
        for(int i{1};i+1<n;++i) dp[i][i] = nums[i-1] * nums[i] * nums[i+1];
        for(int i{1};i<n;++i) {
            for(int j{0};(ei = j+i)<n;++j) {
                mult = (j>0 ? nums[j-1] : 1) * (ei+1<n ? nums[ei+1] : 1);
                dp[j][ei] = max(dp[j+1][ei] + nums[j]*mult, dp[j][ei-1] + nums[ei]*mult);
                for(int k{j+1};k<ei;++k) {
                    dp[j][ei] = max(dp[j][ei], dp[j][k-1] + dp[k+1][ei] + nums[k]*mult);
                }
            }
        }
        return dp.front().back();
    }
public:
    int maxCoins(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};