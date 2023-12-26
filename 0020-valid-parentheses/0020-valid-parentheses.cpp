class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '[') st.emplace(ch);
            else{
                if(st.empty()|| ch == ')' && st.top() != '(' || ch == '}' && st.top() != '{' || ch == ']' && st.top() != '[') return false;
                else st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};