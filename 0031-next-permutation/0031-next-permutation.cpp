class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sml{0}, cmp{0}, n{(int)nums.size()};
        for(int i{1};i<n;++i){
            if(nums[i] > nums[i-1]) {
                sml = i;
                cmp = i-1;
            } else if (nums[i] > nums[cmp] && nums[i] < nums[sml]) {
                sml = i;
            }
        }
        if(sml == 0) reverse(nums.begin(), nums.end());
        else{
            swap(nums[sml], nums[cmp]);
            sort(nums.begin()+cmp+1, nums.end());
        }
    }
};