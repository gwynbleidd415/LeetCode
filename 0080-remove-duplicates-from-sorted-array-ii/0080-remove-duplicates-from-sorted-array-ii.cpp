class Solution {
private:
    int solution1(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int i{2};
        for(int j{2};j<nums.size();++j) {
            if(nums[j]!=nums[i-2]) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
public:
    int removeDuplicates(vector<int>& nums) {
        return solution1(nums);
    }
};