class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n((int)nums.size()), i{0}, j, k, n1{n-1};
        for(int itr: nums) cout << itr << ' ';
        cout << '\n';
        vector<vector<int>> ans;
        int tSum;
        while(i<n1){
            j = i+1, k = n1;
            while(j<k){
                // while(j<k && nums[j] == nums[j+1]) ++j;
                tSum = nums[i] + nums[j] + nums[k];
                if(tSum < 0){
                    ++j;
                } else if(tSum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j, --k;
                    while(j<k && nums[j] == nums[j-1]) ++j;
                    while(k>j && nums[k] == nums[k+1]) --k;
                } else {
                    --k;
                }
            }
            ++i;
            while(i<n && nums[i] == nums[i-1]) ++i;
        }
        return ans;
    }
};