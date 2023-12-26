class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i{0};i<nums.size();++i){
            while(nums[i] > 0 && nums[i] < nums.size() && nums[i] != i && nums[nums[i]] != nums[i]){
                swap(nums[i], nums[nums[i]]);
            }
        }
        for(int i{1};i<nums.size();++i){
            if(nums[i] != i) return i;
        }
        if(nums[0] == nums.size()){
            return nums.size()+1;
        }
        return nums.size();
    }
};