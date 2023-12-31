class Solution {
public:
    int findMin(vector<int>& nums) {
        int l{0}, r = nums.size()-1, mid;
        while(l<r){
            mid = (l+r)>>1;
            if(nums[r] > nums[mid]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};