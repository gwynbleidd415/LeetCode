class Solution {
    int merge(vector<int> &nums, int s, int m, int e) {
        int sz = e-s+1;
        int rps{0};
        vector<int> nnums(sz);
        int js{m+1};
        int i{s}, j{js}, k{0};
        int lgi{s};
        long tar;
        bool dj{true};
        // for(int ii{js};ii<=e;++ii) {

        // }
        while(i<=m && j<=e) {
            if(lgi < js && dj) {
                tar = (long)nums[j] << 1;
                lgi = upper_bound(nums.begin() + lgi, nums.begin()+js, tar) - nums.begin();
                if(lgi < js) {
                    // printf("%d %d %d %d %d %d\n", s, m, e, i, j, lgi);
                    rps += js-lgi;
                } 
                dj = false;
            }
            if(nums[i] > nums[j]) nnums[k++] = nums[j++], dj = true;
            else nnums[k++] = nums[i++];
        }
        while(i<=m) nnums[k++] = nums[i++];
        while(j<=e) {
            nnums[k++] = nums[j++];
            if(lgi < js && j<=e) {
                tar = (long)nums[j] << 1;
                lgi = upper_bound(nums.begin() + lgi, nums.begin()+js, tar) - nums.begin();
                if(lgi < js) {
                    rps += js-lgi;
                } 
            }
        }
        for(i=s, k=0;k<sz;++k, ++i) {
            nums[i] = nnums[k];
        }
        return rps;
    }
    int mergeSort(vector<int> &nums, int s, int e) {
        if(s == e) return 0;
        int m = (s+e)>>1;
        int left = mergeSort(nums, s, m);
        int right = mergeSort(nums, m+1, e);
        return left + right + merge(nums, s, m, e);
    }
    int solution1(vector<int> &nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
public:
    int reversePairs(vector<int>& nums) {
        return solution1(nums);
    }
};