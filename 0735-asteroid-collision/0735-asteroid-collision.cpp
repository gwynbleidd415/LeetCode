class Solution {
private:
    vector<int> solution1(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();
        for(int i{0};i<n;++i) {
            while(!ans.empty() && ans.back()>0 && ans.back()<-asteroids[i]) ans.pop_back();
            if(ans.empty() || asteroids[i]>0 || ans.back()<0) ans.push_back(asteroids[i]);
            else if(ans.back() == -asteroids[i]) ans.pop_back();
        }
        return ans;
    }
    vector<int> solution2(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();
        int i{0};
        while(i<n) {
            if(ans.empty() || asteroids[i]>0 || ans.back()<0) ans.push_back(asteroids[i]), ++i;
            else if(ans.back() == -asteroids[i]) ans.pop_back(), ++i;
            else if(ans.back() > -asteroids[i]) ++i;
            else while(!ans.empty() && ans.back()>0 && ans.back()<-asteroids[i]) ans.pop_back();
        }
        return ans;
    }
    vector<int> solution3(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int asteroid: asteroids) {
            if(asteroid > 0) {
                st.push(asteroid);
                continue;
            }
            while(!st.empty() && st.top() < -asteroid) st.pop();
            if(st.empty()) ans.push_back(asteroid);
            else if(st.top() == -asteroid) st.pop();
        }
        int sz = ans.size();
        while(!st.empty()) ans.push_back(st.top()), st.pop();
        reverse(ans.begin()+sz, ans.end());
        return ans;
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // return solution1(asteroids);
        // return solution2(asteroids);
        return solution3(asteroids);
    }
};