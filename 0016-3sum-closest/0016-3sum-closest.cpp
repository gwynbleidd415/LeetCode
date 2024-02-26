class Solution {
private:
    int solution1(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), n1 = n-1, n2 = n-2;
        int ans{nums[0] + nums[1] + nums[2]};
        for(int i{0};i<n2;++i) {
            int j{i+1}, k{n1};
            while(j<k) {
                int summ = nums[i] + nums[j] + nums[k];
                if(abs(summ-target) < abs(ans-target)) ans = summ;
                if(summ > target) --k;
                else if(summ < target) ++j;
                else return target;
            }
        }
        return ans;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return solution1(nums, target);
    }
};
