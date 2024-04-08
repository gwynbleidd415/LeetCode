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
    int solution2(vector<int>& prices) {
        int b1{INT_MAX}, b2{INT_MAX}, p1{0}, p2{0};
        for(int price: prices) {
            b1 = min(b1, price);
            p1 = max(p1, price - b1);
            b2 = min(b2, price - p1);
            p2 = max(p2, price - b2);
        }
        return p2;
    }
public:
    Solution(){
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
    }
    int maxProfit(vector<int>& prices) {
        // return solution1(prices);
        return solution2(prices);
    }
};