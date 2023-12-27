class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ap = 0, bp = 0;
        int length = nums1.size() + nums2.size();
        int mid = (length - 1) / 2;

        while(ap+bp < mid && ap < nums1.size() && bp < nums2.size()) {
            if(nums1[ap] < nums2[bp]){
                ++ap;
            } else {
                ++bp;
            }
        }
        if(ap == nums1.size()){
            if(length & 1){
                return nums2[mid-ap];
            }
            return (double)(nums2[mid-ap] + nums2[mid-ap+1])/2;
        }
        if(bp == nums2.size()){
            if(length & 1){
                return nums1[mid-bp];
            }
            return (double)(nums1[mid-bp]+nums1[mid-bp+1])/2;
        }
        if(length & 1){
            return min(nums1[ap], nums2[bp]);
        }
        if(nums1[ap] < nums2[bp]){
            if(ap != nums1.size() - 1){
                return (double)(nums1[ap] + min(nums1[ap+1], nums2[bp]))/2;
            }
            return (double)(nums1[ap] + nums2[bp]) / 2;
        }
        if(bp != nums2.size() - 1) {
            return (double)(nums2[bp] + min(nums2[bp+1], nums1[ap]))/2;
        }
        return (double)(nums1[ap] + nums2[bp]) / 2;
    }
};