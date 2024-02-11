class Solution {
private:
    int solution1(vector<int>& nums) {
        int maxNeg{1}, maxPos{1}, ans{nums.front()};
        for(int num:nums){
            maxPos *= num, maxNeg *= num;
            if(num < 0) swap(maxPos, maxNeg);
            ans = max(ans, maxPos);
            if(maxPos <= 0) maxPos = 1;
            if(maxNeg >= 0) maxNeg = 1;
        }
        return ans;
    }
    int solution2(vector<int>& nums) {
        int prefix{1}, suffix{1}, ans{nums[0]};
        for(int i{0}, j=nums.size()-1;i<nums.size();++i, --j) {
            prefix *= nums[i], suffix *= nums[j];
            ans = max({ans, prefix, suffix});
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }
        return ans;
    }
public:
    int maxProduct(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};