class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int si = 0, ei = n - 1;
        int ans = 0;
        while(si < ei){
            ans = max(ans, (ei - si) * min(height[ei], height[si]));
            if(height[ei] < height[si]) --ei;
            else if(height[ei] == height[si]) ++si, --ei;
            else ++si;
        }
        return ans;
    }
};
