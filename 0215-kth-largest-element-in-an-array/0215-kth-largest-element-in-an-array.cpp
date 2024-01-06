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
            else l = li+1;
        }
        return 0;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return solution1(nums, k);
    }
};