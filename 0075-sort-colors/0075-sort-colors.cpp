class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> hm(3, 0);
        for(int num:nums) ++hm[num];
        int k{-1};
        for(int i{0};i<3;++i){
            for(int j{0};j<hm[i];++j){
                nums[++k] = i;
            }
        }
    }
};