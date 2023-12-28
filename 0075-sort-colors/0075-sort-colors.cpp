class Solution {
public:
    void sortColors(vector<int>& nums) {
        // vector<int> hm(3, 0);
        // for(int num:nums) ++hm[num];
        // int k{-1};
        // for(int i{0};i<3;++i){
        //     for(int j{0};j<hm[i];++j){
        //         nums[++k] = i;
        //     }
        // }

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
};