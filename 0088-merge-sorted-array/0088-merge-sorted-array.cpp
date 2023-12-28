const static int initialize = [] { 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(0); 
    std::cout.tie(0); 
    return 0; 
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i{m-1}, j{n-1},k{n+m-1};
        while(i>=0 && j>=0 && k>=0){
            if(nums1[i]<nums2[j]) nums1[k] = nums2[j--];
            else nums1[k]=nums1[i--];
            --k;
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
        // int i{m-1}, j{n-1};
        // for(int k{n+m-1};k>=0;--k){
        //     if(i<0) nums1[k] = nums2[j--];
        //     else if(j<0) nums1[k] = nums1[i--];
        //     else{
        //         if(nums1[i]<nums2[j]) nums1[k] = nums2[j--];
        //         else nums1[k]=nums1[i--];
        //     }
        // }
    }
};