class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans{0}, count{0};
        for(int num: nums) {
            if(num == 0) {
                ans = max(ans, count);
                count = 0;
            }
            else ++count;
        }
        ans = max(ans, count);
        return ans;
    }
};