class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i{0};
        while(i<n){
            if(nums[i] < 1 || nums[i] >= n || nums[i] == i || nums[nums[i]] == nums[i]) ++i;
            else swap(nums[i], nums[nums[i]]);
        }
        for(i=1;i<n;++i){
            if(nums[i] != i) return i;
        }
        return nums[0] == n ? n+1 : n;
    }
};