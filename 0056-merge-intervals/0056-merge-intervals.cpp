class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end());
        // vector<vector<int>> ans;
        // int n{(int)intervals.size()};
        // int si{intervals[0][0]}, ei{intervals[0][1]};
        // for(int i{1};i<n;++i){
        //     if(intervals[i][0] > ei) {
        //         ans.push_back({si, ei});
        //         si = intervals[i][0], ei = intervals[i][1];
        //     } else {
        //         ei = max(ei, intervals[i][1]);
        //     }
        // }
        // ans.push_back({si, ei});
        // return ans;

        vector<int> ha(10001, -1);
        int minV{INT32_MAX}, maxV{INT32_MIN};
        vector<vector<int>> ans;
        for(vector<int> &itr: intervals){
            ha[itr[0]] = max(itr[1], ha[itr[0]]);
            minV = min(minV, itr[0]), maxV = max(maxV, itr[0]);
        }
        int si{minV}, ei{ha[minV]};
        for(int i{minV+1};i<=maxV;++i){
            if(ha[i] == -1) continue;
            if(i <= ei) ei = max(ei, ha[i]);
            else {
                ans.push_back({si, ei});
                si = i, ei = ha[i];
            }
        }
        ans.push_back({si, ei});
        return ans;
    }
};