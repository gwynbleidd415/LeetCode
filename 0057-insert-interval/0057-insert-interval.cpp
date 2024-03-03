class Solution {
private:
    vector<vector<int>> solution1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i{0};
        while(i<n && intervals[i].back()<newInterval.front()) {
            ans.push_back(intervals[i]);
            ++i;
        }
        if(i != n) {
            newInterval.front() = min(newInterval.front(), intervals[i].front());
            while(i<n && newInterval.back()>=intervals[i].front()) ++i;
            if(i != 0) newInterval.back() = max(newInterval.back(), intervals[i-1].back());
        }
        ans.push_back(newInterval);
        while(i<n) {
            ans.push_back(intervals[i]);
            ++i;
        }
        return ans;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return solution1(intervals, newInterval);
    }
};