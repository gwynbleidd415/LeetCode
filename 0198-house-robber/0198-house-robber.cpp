class Solution {
    int solution1(vector<int> &nums) {
        pair<int, int> taig{0, 0};
        int temp;
        for(int num: nums) {
            temp = taig.second;
            taig.second = max(taig.first, taig.second);
            taig.first = temp + num;
        }
        return max(taig.first, taig.second);
    }
    int solution2(vector<int> &nums) {
        if(nums.size() == 1) return nums.front();
        vector<int> dp(nums.size() + 1);
        dp[0] = 0, dp[1] = nums.front();
        for(int i{1};i<nums.size();++i) {
            dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
        }
        return dp.back();
    }
public:
    int rob(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};
