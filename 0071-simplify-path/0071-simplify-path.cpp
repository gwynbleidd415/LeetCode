class Solution {
private:
    string solution1(string &path) {
        stack<string> st;
        int n = path.size();
        int i{1}, str{1};
        while(i<n) {
            if(path[i] == '/') {
                if(str!=i) {
                    string substr = path.substr(str, i-str);
                    if(substr == "..") {
                        if(!st.empty()) st.pop();
                    } else if(substr != ".") {
                        st.push(substr);
                    }
                }
                str = i+1;
            }
            ++i;
        }
        if(str!=i) {
            string substr = path.substr(str, i-str);
            if(substr == "..") {
                if(!st.empty()) st.pop();
            } else if(substr != ".") {
                st.push(substr);
            }
        }
        string ans{""};
        while(!st.empty()) ans = "/" + st.top() + ans, st.pop();
        if(ans == "") return "/";
        return ans;
    }
public:
    string simplifyPath(string path) {
        return solution1(path);
    }
};
