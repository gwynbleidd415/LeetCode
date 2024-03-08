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
    string solution2(string &path) {
        istringstream iss(path);
        string temp;
        vector<string> paths;
        while(getline(iss, temp, '/')) {
            if(temp.empty() || temp == ".") continue;
            if(temp == "..") {
                if(!paths.empty()) paths.pop_back();
            } else paths.push_back(temp);
        }
        string ans{""};
        for_each(paths.begin(), paths.end(), [&ans](string &str) {
            ans.push_back('/');
            ans += str;
        });
        if(ans == "") return "/";
        return ans;
    }
public:
    string simplifyPath(string path) {
        // return solution1(path);
        return solution2(path);
    }
};
