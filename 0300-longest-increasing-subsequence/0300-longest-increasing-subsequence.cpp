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
    int solution2(vector<int>& nums) {
        vector<int> lis;
        vector<int>::iterator lisi;
        lis.reserve(nums.size());
        lis.push_back(nums.front());
        int n = nums.size();
        for(int i{1};i<n;++i) {
            lisi = lower_bound(lis.begin(), lis.end(), nums[i]);
            if(lisi == lis.end()) lis.push_back(nums[i]);
            else *lisi = nums[i];
        }
        return lis.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};