class Solution {
    int solution1(vector<int>& nums) {
        int  count{1}, ans{INT_MIN};
        for(int num: nums) {
            if(num == ans) ++count;
            else if(count == 1) ans = num;
            else --count;
        }
        return ans;
    }
public:
    int majorityElement(vector<int>& nums) {
        return solution1(nums);
    }
};