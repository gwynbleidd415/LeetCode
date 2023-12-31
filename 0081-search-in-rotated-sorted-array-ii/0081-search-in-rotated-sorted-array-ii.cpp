class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l{0}, r=nums.size()-1, mid;
        while(l<=r){
            mid = (l+r)>>1;
            cout<<l<<' '<<r<<' '<<mid<<'\n';
            if(nums[mid] == target) return true;
            if(nums[l]<nums[mid] || nums[r] < nums[mid]){
                if(target >= nums[l] && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else if(nums[l]>nums[mid] || nums[r]>nums[mid]) {
                if(target <= nums[r] && target > nums[mid]) l = mid + 1;
                else r = mid - 1;
            } else {
                ++l, --r;
            }
        }
        return false;
    }
};