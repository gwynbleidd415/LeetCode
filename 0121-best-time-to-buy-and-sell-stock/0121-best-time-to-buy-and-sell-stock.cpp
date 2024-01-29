class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans{0}, minn{prices.front()};
        for(int i{1};i<prices.size();++i) {
            if(prices[i] > minn) {
                ans = max(ans, prices[i]-minn);
            } else if(prices[i] < minn) {
                minn = prices[i];
            }
        }
        return ans;
    }
};
