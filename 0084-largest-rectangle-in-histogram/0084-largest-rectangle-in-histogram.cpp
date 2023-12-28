const static int initialize = [] { 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(0); 
    std::cout.tie(0); 
    return 0; 
}();

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        heights.push_back(0);
        int ans{0}, n{(int)heights.size()}, tempTop;
        for(int i{0};i<n;++i){
            while(st.size() > 1 && heights[st.top()] >= heights[i]){
                tempTop = st.top();
                st.pop();
                ans = max(ans, (i-st.top()-1)*heights[tempTop]);
            }
            st.push(i);
        }
        return ans;
        // stack<int> st;
        // st.push(-1);
        // int ans{0}, n{(int)heights.size()}, tempTop;
        // for(int i{0};i<n;++i){
        //     while(st.size() > 1 && heights[st.top()] >= heights[i]){
        //         tempTop = st.top();
        //         st.pop();
        //         ans = max(ans, (i-st.top()-1)*heights[tempTop]);
        //     }
        //     st.push(i);
        // }
        // while(st.size()>1){
        //     tempTop = st.top();
        //     st.pop();
        //     ans = max(ans, (n-st.top()-1)*heights[tempTop]);
        // }
        // return ans;
    }
};