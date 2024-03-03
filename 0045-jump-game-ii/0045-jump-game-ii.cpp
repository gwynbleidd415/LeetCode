class Solution {
private:
    int solution1(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int nJumps{0};
        int maxReach{0}, cend{0}, itr{0};
        while(true) {
            for(;itr<=cend;++itr) {
                if(itr + nums[itr] > maxReach) {
                    maxReach = itr + nums[itr];
                    if(maxReach >= n-1) return nJumps + 1;
                }
            }
            ++nJumps;
            cend = maxReach;
        }
        return nJumps;
    }
public:
    int jump(vector<int>& nums) {
        return solution1(nums);
    }
};