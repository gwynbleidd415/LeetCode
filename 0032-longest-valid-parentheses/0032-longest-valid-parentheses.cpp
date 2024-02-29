class Solution {
private:
    int solution1(string &s) {
        stack<int> st;
        int ans{0}, n = s.size();
        st.push(-1);
        for(int i{0};i<n;++i) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();
                if(st.size() == 0) {
                    st.push(i);
                } else {
                    ans = max(ans, i-st.top());
                }
            }
        }
        return ans;
    }
public:
    int longestValidParentheses(string s) {
        return solution1(s);
    }
};