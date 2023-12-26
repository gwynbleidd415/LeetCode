class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '[') st.emplace(ch);
            else{
                if(st.size() == (size_t)0 || ch == ')' && st.top() != '(' || ch == '}' && st.top() != '{' || ch == ']' && st.top() != '[') return false;
                else st.pop();
            }
        }
        if(st.size() != (size_t)0) return false;
        return true;
    }
};