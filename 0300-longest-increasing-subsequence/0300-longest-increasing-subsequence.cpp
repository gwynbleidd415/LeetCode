class Solution {
private:
    int solution1(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans{1}, n = nums.size();
        for(int i{1};i<n;++i) {
            for(int j{0};j<i;++j){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solution1(nums);
    }
};