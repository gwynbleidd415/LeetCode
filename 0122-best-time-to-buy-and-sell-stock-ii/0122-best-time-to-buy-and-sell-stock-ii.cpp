class Solution {
private:
    int solution1(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> gr(n);
        gr.back() = n-1;
        st.push(n-1);
        for(int i{n-2};i>=0;--i) {
            while(!st.empty() && prices[st.top()] <= prices[i]) st.pop();
            if(st.empty()) gr[i] = i;
            else gr[i] = st.top();
            st.push(i);
        }
        int i{0}, profit{0};
        while(i<n) {
            if(gr[i] == i) {
                ++i;
                continue;
            }
            for(int j{i+1};j<gr[i];++j) {
                if(prices[j] < prices[i]) {
                    i = j;
                    continue;
                }
            }
            profit += prices[gr[i]] - prices[i];
            i = gr[i];
        }
        return profit;
    }
    int solution2(vector<int> &prices) {
        int n1 = prices.size()-1;
        int ans{0};
        for(int i{0};i<n1;++i) {
            if(prices[i]<prices[i+1]) ans += prices[i+1]-prices[i];
        }
        return ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        // return solution1(prices);
        return solution2(prices);
    }
};