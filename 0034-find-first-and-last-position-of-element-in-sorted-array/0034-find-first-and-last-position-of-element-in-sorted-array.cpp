class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int startPos, endPos;
        int l{0}, r{(int)nums.size()-1}, mid, pa{0};
        while(l<=r){
            mid = (l+r)>>1;
            if(nums[mid] >= target) r = mid-1, pa=mid;
            else l = mid+1;
        }
        // cout << l << ' ' << r << ' ' << mid << ' ' << pa << '\n';
        if(nums[pa]!=target) return {-1,-1};
        else startPos = l;
        l = 0, r = nums.size()-1;
        while(l<=r){
            mid = (l+r)>>1;
            if(nums[mid]<=target) l = mid+1, pa = mid;
            else r = mid-1;
        }
        endPos = pa;
        return {startPos, endPos};
    }
};