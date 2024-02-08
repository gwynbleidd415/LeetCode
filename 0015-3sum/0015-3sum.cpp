class Solution {
private:
    vector<vector<int>> solution1(vector<int>& nums) {
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
                    // while(j<k && nums[j] == nums[j-1]) ++j;
                    // while(k>j && nums[k] == nums[k+1]) --k;
                } else {
                    --k;
                }
                if(j>i+1){
                    while(j<k && nums[j] == nums[j-1]) ++j;
                }
                if(k < n1){
                    while(k>j && nums[k] == nums[k+1]) --k;
                }
            }
            ++i;
            while(i<n && nums[i] == nums[i-1]) ++i;
        }
        return ans;
    }
    vector<vector<int>> solution2(vector<int>& nums) {
        int n = nums.size(), n1{n-1}, n2{n-2};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i{0}, j, k, summ;
        while(i<n2) {
            j = i+1, k = n1;
            while(j < k) {
                summ = nums[i] + nums[j] + nums[k];
                if(summ > 0) {
                    --k;
                    while(k>j && nums[k] == nums[k+1]) --k;
                } else if(summ < 0) {
                    ++j;
                    while(j<k && nums[j] == nums[j-1]) ++j;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    --k, ++j;
                    while(j<k && nums[j] == nums[j-1]) ++j;
                    while(k>j && nums[k] == nums[k+1]) --k;
                }
            }
            ++i;
            while(i < n2 && nums[i] == nums[i-1]) ++i;
        }
        return ans;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }
};