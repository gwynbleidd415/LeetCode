class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int length = nums.size();
        // for (int i = 0; i < length; ++i) {
        //     for (int j = i + 1; j < length; ++j) {
        //         if (nums[i] + nums[j] == target)
        //             return vector<int>{i, j};
        //     }
        // }
        // return vector<int>{-1, -1};

        vector<int> index(nums.size());
        iota(index.begin(), index.end(), 0);

        sort(index.begin(), index.end(), [&nums](int &a, int &b){
            return nums[a] < nums[b];
        });

        int start = 0, end = nums.size() - 1;
        while(end > start){
            int summ = nums[index[start]] + nums[index[end]];
            if(summ == target){
                return vector<int>{index[start], index[end]};
            } else if(summ < target){
                ++start;
            } else {
                --end;
            }
        }

        return vector<int>{-1, -1};
    }
};