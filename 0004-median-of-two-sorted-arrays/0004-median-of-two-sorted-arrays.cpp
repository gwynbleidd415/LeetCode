class Solution {
private:
    double medianHelper(vector<int> &nums1, vector<int> &nums2){
        int n{(int)nums1.size()}, m{(int)nums2.size()};
        int ap = 0, bp = 0;
        int length = n + m;
        int mid = (length - 1) / 2;

        while(ap+bp < mid && ap < n && bp < m) {
            if(nums1[ap] < nums2[bp]){
                ++ap;
            } else {
                ++bp;
            }
        }

        if(ap == n){
            if(length & 1){
                return nums2[mid-ap];
            }
            return (double)(nums2[mid-ap] + nums2[mid-ap+1])/2;
        }
        if(bp == m){
            if(length & 1){
                return nums1[mid-bp];
            }
            return (double)(nums1[mid-bp]+nums1[mid-bp+1])/2;
        }
        if(length & 1){
            return min(nums1[ap], nums2[bp]);
        }
        if(nums1[ap] < nums2[bp]){
            if(ap != n - 1){
                return (double)(nums1[ap] + min(nums1[ap+1], nums2[bp]))/2;
            }
            return (double)(nums1[ap] + nums2[bp]) / 2;
        }
        if(bp != m - 1) {
            return (double)(nums2[bp] + min(nums2[bp+1], nums1[ap]))/2;
        }
        return (double)(nums1[ap] + nums2[bp]) / 2;
    }
    double medianHelper2(vector<int> &nums1, vector<int> &nums2){
        if(nums1.size() > nums2.size())
            return medianHelper(nums2, nums1);
        int n1 = nums1.size(), n2 = nums2.size();
        int l1{0}, r1{n1}, lh{(n1+n2+1)>>1}, mid1, mid2, ml1, ml2, mr1, mr2;
        while(r1>=l1){
            mid1 = (l1+r1)>>1, mid2 = lh-mid1;
            ml1 = mid1 == 0 ? INT_MIN : nums1[mid1-1];
            ml2 = mid2 == 0 ? INT_MIN : nums2[mid2-1];
            mr1 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            mr2 = mid2 < n2 ? nums2[mid2] : INT_MAX;
            if(ml1 <= mr2 && ml2 <= mr1) {
                if((n1^n2)&1) return max(ml1, ml2);
                else return (double)(max(ml1, ml2)+min(mr1, mr2))/2; 
            }
            if(ml1 > mr2) r1 = mid1-1;
            else l1 = mid1 + 1;
        }
        return -1;
    }
    double medianHelper3(vector<int> &nums1, vector<int> &nums2){
        if(nums1.size() > nums2.size())
            return medianHelper(nums2, nums1);
        int n1 = nums1.size(), n2 = nums2.size();
        int l1{0}, r1{n1}, lh{(n1+n2+1)>>1}, mid1, mid2, ml1, ml2, mr1, mr2;
        while(r1>=l1){
            mid1 = (l1+r1)>>1, mid2 = lh-mid1;
            ml1 = mid1 == 0 ? INT_MIN : nums1[mid1-1];
            ml2 = mid2 == 0 ? INT_MIN : nums2[mid2-1];
            mr1 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            mr2 = mid2 < n2 ? nums2[mid2] : INT_MAX;
            if(ml1 <= mr2 && ml2 <= mr1) {
                if((n1^n2)&1) return max(ml1, ml2);
                else return (double)(max(ml1, ml2)+min(mr1, mr2))/2; 
            }
            if(ml1 > mr2) r1 = mid1-1;
            else l1 = mid1 + 1;
        }
        return -1;
    }
    double medianHelper4(vector<int> &nums1, vector<int> &nums2){
        if(nums1.size() > nums2.size())
            return medianHelper(nums2, nums1);
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 == 0){
            if(n2&1) return nums2[n2>>1];
            else return (double)(nums2[n2>>1] + nums2[(n2>>1)-1])/2;
        }
        int l1{0}, r1{n1}, lh{(n1+n2)>>1}, mid1, mid2, l2;
        do{
            mid1 = (l1+r1)>>1, mid2 = lh-mid1;
            if(mid2!=0 && nums2[mid2-1] > nums1[mid1]) l1 = mid1+1;
            else r1 = mid1;
        } while(r1>l1);
        l2 = lh - l1;
        if((n1^n2)&1){
            if(l1==n1) return nums2[l2];
            else if(l2==n2) return nums1[l1];
            return min(nums1[l1], nums2[l2]);
        }
        int left = max(l1>0?nums1[l1-1]:INT_MIN, l2>0?nums2[l2-1]:INT_MIN);
        int right = min(l1<n1?nums1[l1]:INT_MAX, l2<n2?nums2[l2]:INT_MAX);
        return (double)(left+right)/2;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return medianHelper4(nums1, nums2);
    }
};