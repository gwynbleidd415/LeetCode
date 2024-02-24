class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        int i = min(n, k);
        for(int j{0};j<i;++j) pq.push(nums[j]);
        for(;i<n;++i) {
            if(nums[i] <= pq.top()) continue;
            pq.pop();
            pq.push(nums[i]);
        }
    }
    int add(int val) {
        if(pq.size() < k) pq.push(val);
        else if(pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
