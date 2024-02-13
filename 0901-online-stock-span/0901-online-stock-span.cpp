class StockSpanner {
private:
    stack<pair<int, int>> st;
    int currDay;
public:
    StockSpanner() {
        st.push({INT_MAX, 0});
        currDay = 0;
    }
    
    int next(int price) {
        ++currDay;
        while(st.top().first <= price) st.pop();
        int ans = currDay - st.top().second;
        st.push({price, currDay});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */