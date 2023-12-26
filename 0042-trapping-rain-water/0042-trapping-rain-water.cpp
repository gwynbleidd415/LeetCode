class Solution {
private:
    int calcAnsAddRBig(vector<int> &height, vector<int> &summ, int l, int r){
        return height[l] * (r - l - 1) - (summ[r-1] - summ[l]);
    }
    int calcAnsAddLBig(vector<int> &height, vector<int> &summ, int l, int r){
        return height[r] * (r - l - 1) - (summ[r-1] - summ[l]);
    }
public:
    int trap(vector<int>& height) {
        int ans{0}, n((int)height.size()), temp;
        stack<int> st;
        vector<int> summ(n);
        summ[0] = height[0];
        for(int i{1};i<n;++i) summ[i] = summ[i-1] + height[i];
        for(int i{0};i<n;++i){
            temp = -1;
            while(!st.empty() && height[st.top()] <= height[i]){
                temp = st.top();
                st.pop();
            }
            if(temp!=-1 && st.empty()){
                ans += calcAnsAddRBig(height, summ, temp, i);
            }
            // cout << i << ' ' << temp << ' ' << ans << '\n';
            st.push(i);
        }
        while(st.size() > 1){
            temp = st.top();
            st.pop();
            ans += calcAnsAddLBig(height, summ, st.top(), temp);
        }
        return ans;
    }
};