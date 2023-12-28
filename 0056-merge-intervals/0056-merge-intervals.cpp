class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a.front() < b.front();
        });
        vector<vector<int>> ans;
        int n{(int)intervals.size()};
        int si{intervals[0][0]}, ei{intervals[0][1]};
        for(int i{1};i<n;++i){
            if(intervals[i][0] > ei) {
                ans.push_back({si, ei});
                si = intervals[i][0], ei = intervals[i][1];
            } else {
                ei = max(ei, intervals[i][1]);
            }
        }
        ans.push_back({si, ei});
        return ans;
    }
};