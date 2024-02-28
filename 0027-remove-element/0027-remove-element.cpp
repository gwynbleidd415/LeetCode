class Solution {
private:
    int solution1(vector<int>& nums, int val) {
        int i{0}, j = nums.size()-1;
        while(i<=j) {
            if(nums[i] == val) nums[i] = nums[j--];
            else ++i;
        }
        return j+1;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        return solution1(nums, val);
    }
};