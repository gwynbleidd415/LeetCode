class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int n1 = nums.size()-1;
        int l{0}, r = n1, mid;
        while(l+1<r){
            mid = (l+r)>>1;
            // cout<<l<<' '<<mid<<' '<<r<<'\n';
            if(nums[r] >= nums[mid]) l = mid+1;
            else if(nums[l] >= nums[mid]) r = mid - 1;
            else{
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
                if(nums[mid+1]>nums[mid]) l = mid+1;
                else r = mid-1;
            }
        }
        // cout<<l<<' '<<' '<<r<<'\n';
        return nums[l] > nums[r] ? l : r;
    }
};