class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans{0}, maxx{INT_MIN}, n{(int)nums.size()};
        int l{0}, r{0} ,tSum{0};
        while(r<n){
            maxx = max(maxx, nums[r]);
            tSum += nums[r++];
            while(l<r && tSum < 0) tSum -= nums[l++];
            ans = max(tSum, ans);
        }
        if(maxx <= 0) return maxx;
        return ans;
    }
};