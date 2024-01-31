class Solution {
    int solution1(vector<int>& nums) {
        int fast{0}, slow{0};
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(fast != slow);
        fast = 0;
        while(fast!=slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
public:
    int findDuplicate(vector<int>& nums) {
        return solution1(nums);
    }
};
