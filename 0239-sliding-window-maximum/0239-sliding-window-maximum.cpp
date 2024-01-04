class Solution {
private:
    vector<int> solution1(vector<int>& nums, int k) {
        deque<int> dqu;
        vector<int> ans(nums.size()-k+1);
        int i{0}, j{1};
        for(;i<k;++i) {
            while(!dqu.empty() && nums[dqu.back()]<nums[i]) dqu.pop_back();
            dqu.push_back(i);
        }
        ans[0] = nums[dqu.front()];
        for(;i<nums.size();++i, ++j) {
            if(dqu.front() < j) dqu.pop_front();
            while(!dqu.empty() && nums[dqu.back()]<nums[i]) dqu.pop_back();
            dqu.push_back(i);
            ans[j] = nums[dqu.front()];
        }
        return move(ans);
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return move(solution1(nums, k));
    }
};