class Solution {
private:
    vector<int> solution1(vector<int>& nums, int k) {
        int minn{INT_MAX}, maxx{INT_MIN};
        for(int num: nums) {
            if(minn > num) minn = num;
            if(maxx < num) maxx = num;
        }
        vector<int> count(maxx - minn + 1);
        for(int num: nums) ++count[num-minn];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i{0};i<count.size();++i) {
            if(count[i] == 0) continue;
            if(pq.size() < k) pq.push({count[i], i+minn});
            else if (pq.top().first < count[i]) pq.pop(), pq.push({count[i], i+minn});
        }
        vector<int> ans(k);
        for(int i{0};i<k;++i) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return solution1(nums, k);
    }
};