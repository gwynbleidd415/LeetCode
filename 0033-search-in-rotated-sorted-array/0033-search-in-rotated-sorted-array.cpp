class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while(l < r){
            mid = (l+r)>>1;
            cout<<l<<' '<<r<<' '<<mid<<'\n';
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[r]){
                if(target >= nums[l] && target < nums[mid]) r = mid-1;
                else l = mid+1; 
            } else {
                if(target <= nums[r] && target > nums[mid]) l = mid+1;
                else r = mid-1;
            }
        }
        if(l == r && nums[l] == target) return l;
        return -1;
    }
};