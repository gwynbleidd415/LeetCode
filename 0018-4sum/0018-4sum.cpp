class Solution {
    vector<vector<int>> solution1(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};
        int n3{n-3}, n2{n-2};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i{0};
        while(i<n3) {
            int j = i+1;
            while(j<n2) {
                int k = j+1, l = n-1;
                while(k<l) {
                    long summ = (long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(summ == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                    if(summ > target) {
                        --l;
                        while(l>k && nums[l] == nums[l+1]) --l;
                    }
                    else {
                        ++k;
                        while(k<l && nums[k] == nums[k-1]) ++k;
                    }
                }
                ++j;
                while(j<n2 && nums[j] == nums[j-1]) ++j;
            }
            ++i;
            while(i<n3 && nums[i] == nums[i-1]) ++i;
        }
        return ans;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return solution1(nums, target);
    }
};