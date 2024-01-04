class Solution {
private:
    vector<int> nextGreaterElementSolver1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        int n = nums2.size();
        vector<int> dp(n);
        stack<int> st;
        for(int i{n-1};i>=0;--i) {
            umap[nums2[i]] = i;
            while(!st.empty() && st.top() < nums2[i]) st.pop();
            if(st.empty()) dp[i] = -1;
            else dp[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i{0};i<nums1.size();++i) ans[i] = dp[umap[nums1[i]]];
        return ans;
    }
    vector<int> nextGreaterElementSolver2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        int n = nums2.size();
        vector<int> dp(n);
        int temp{n};
        for(int i{n-1};i>=0;--i) {
            umap[nums2[i]] = i;
            while(temp != n && nums2[temp] < nums2[i]) temp = dp[temp];
            dp[i] = temp;
            temp = i;
        }
        nums2.push_back(-1);
        vector<int> ans(nums1.size());
        for(int i{0};i<nums1.size();++i) ans[i] = nums2[dp[umap[nums1[i]]]];
        return ans;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // return nextGreaterElementSolver1(nums1, nums2);
        return nextGreaterElementSolver2(nums1, nums2);
    }
};