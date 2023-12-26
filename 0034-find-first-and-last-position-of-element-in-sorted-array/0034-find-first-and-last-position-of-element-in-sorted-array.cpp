class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int startPos, endPos;
        int l{0}, r{(int)nums.size()-1}, mid;
        while(l<r){
            mid = (l+r)>>1;
            if(nums[mid] >= target) r = mid;
            else l = mid+1;
        }
        // cout << l << ' ' << r << ' ' << mid << '\n';
        if(nums[l]!=target) return {-1,-1};
        else startPos = l;
        l = 0, r = nums.size()-1;
        while(l<r){
            mid = (l+r+1)>>1;
            if(nums[mid]>target) r = mid-1;
            else l = mid;
        }
        endPos = l;
        return {startPos, endPos};
    }
};