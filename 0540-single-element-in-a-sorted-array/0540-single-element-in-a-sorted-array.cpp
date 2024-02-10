class Solution {
private:
    int solution1(vector<int>& nums) {
        int xorr{0};
        for(int num: nums) xorr ^= num;
        return xorr;
    }
    int solution2(vector<int>& nums) {
        int l{0}, r = nums.size()-1, mid;
        while(l < r) {
            mid = (l+r)>>1;
            if(((mid&1) && nums[mid-1]!=nums[mid]) || (!(mid&1) && nums[mid+1] != nums[mid])) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};