class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l{0}, r = nums.size(), m;
        while(l<r) {
            m = (l+r)>>1;
            if(nums[m] < target) l = m+1;
            else r = m;
        }
        return l;
    }
};