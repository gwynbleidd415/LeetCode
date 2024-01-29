class Solution {
    void solution1(vector<int>& nums) {
        vector<int> hm(3, 0);
        for(int num:nums) ++hm[num];
        int k{-1};
        for(int i{0};i<3;++i){
            for(int j{0};j<hm[i];++j){
                nums[++k] = i;
            }
        }
    }
    void solution2(vector<int>& nums) {
        int itr0{0}, itr1{0}, itr2{(int)nums.size()-1};
        while(itr1 <= itr2){
            if(nums[itr1] == 0){
                swap(nums[itr0], nums[itr1]);
                ++itr0, ++itr1;
            } else if(nums[itr1] == 1){
                ++itr1;
            } else {
                swap(nums[itr1],nums[itr2]);
                --itr2;
            }
        }
    }
    void solution3(vector<int>& nums) {
        vector<int> hm(3, 0);
        for(int num:nums) ++hm[num];
        hm[1] += hm[0];
        hm[2] += hm[1];
        int n{(int)nums.size()};
        for(int i{0};i<n;++i){
            if(i < hm[0]) nums[i] = 0;
            else if(i < hm[1]) nums[i] = 1;
            else nums[i] = 2;
        }
    }
public:
    void sortColors(vector<int>& nums) {
        // solution1(nums);
        solution2(nums);
        // solution3(nums);
    }
};