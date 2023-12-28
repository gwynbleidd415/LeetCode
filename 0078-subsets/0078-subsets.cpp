class Solution {
private:
    // vector<vector<int>> subsetsHelper(vector<int>& nums, int n){
    //     if(n == -1) return {{}};

    //     vector<vector<int>> subAns = subsetsHelper(nums, n-1);
    //     vector<int> arr;
    //     int m = subAns.size();
    //     for(int i{0}; i< m;++i){
    //         arr = subAns[i];
    //         arr.push_back(nums[n]);
    //         subAns.push_back(arr);
    //     }
    //     return subAns;
    // }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // if(nums.size() == 0) return {{}};

        // return subsetsHelper(nums, nums.size() - 1);

        vector<vector<int>> ans{{}};
        vector<int> arr;

        int n{(int)nums.size()}, m;
        for(int i{0};i<n;++i){
            m = ans.size();
            for(int j{0};j<m;++j){
                arr = ans[j];
                arr.push_back(nums[i]);
                ans.push_back(arr);
            }
        }
        return ans;

    }
};