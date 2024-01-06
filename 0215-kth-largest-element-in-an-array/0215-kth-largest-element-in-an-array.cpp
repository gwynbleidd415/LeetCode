class Solution {
    int solution1(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num: nums) {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
    int solution2(vector<int>& nums, int k) {
        int n = nums.size();
        int nk = n - k;
        int l{0}, r{n-1}, li, ri;
        while(true){
            li = l, ri = r-1;
            while(li <= ri) {
                if(nums[li] > nums[r]) swap(nums[li], nums[ri--]);
                else ++li;
            }
            if(li == nk) return nums[r];
            if(li>nk) r = li-1;
            else l = li + 1,  swap(nums[li], nums[r]);
        }
        return 0;
    }
    int solution3(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return nums.front();
        int nk = n - k;
        int l{0}, r{n-1}, li, ri, rt;
        while(l<=r){
            li = l, ri = r-1, rt = r;
            while(li <= ri) {
                if(nums[li] == nums[r]) {
                    swap(nums[--rt], nums[li]);
                    if(ri == rt) --ri;
                    else swap(nums[ri--], nums[li]);
                }
                else if(nums[li] > nums[r]) swap(nums[li], nums[ri--]);
                else ++li;
            }
            if(li<=nk && li+r-rt>=nk) return nums[r];
            if(li>nk) r = li-1;
            else nk-=r-rt+1, l = li, r = rt-1;
        }
        return 0;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // return solution1(nums, k);
        // return solution2(nums, k);
        return solution3(nums, k);
    }
};
