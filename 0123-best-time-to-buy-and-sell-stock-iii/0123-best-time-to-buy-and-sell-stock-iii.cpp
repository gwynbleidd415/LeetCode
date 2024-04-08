class Solution {
private:
    int solution1(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        vector<int> gp(n);
        int minn{prices.front()}, cp{0};
        for(int i{1};i<n;++i) {
            if(prices[i]<minn) {
                minn = prices[i];
            } else if(prices[i]-minn > cp) {
                cp = prices[i] - minn;
            }
            gp[i] = cp;
        }
        int ans{cp};
        int maxx{prices.back()}; cp = 0;
        for(int i{n-2};i>0;--i) {
            if(prices[i]>maxx) {
                maxx = prices[i];
            } else if(maxx-prices[i] > cp) {
                cp = maxx - prices[i];
            }
            ans = max(gp[i-1]+cp, ans);
        }
        return ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        return solution1(prices);
    }
};