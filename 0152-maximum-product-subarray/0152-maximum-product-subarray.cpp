class Solution {
private:
    int solution1(vector<int>& nums) {
        int maxNeg{1}, maxPos{1}, ans{nums.front()};
        for(int num:nums){
            if(num < 0) swap(maxPos, maxNeg);
            maxPos *= num, maxNeg *= num;
            ans = max(ans, maxPos);
            if(maxPos <= 0) maxPos = 1;
            if(maxNeg >= 0) maxNeg = 1;
        }
        return ans;
    }
public:
    int maxProduct(vector<int>& nums) {
        return solution1(nums);
    }
};