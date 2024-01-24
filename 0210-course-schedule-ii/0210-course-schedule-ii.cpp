class Solution {
private:
    bool solution1Helper(int n, vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited, vector<bool> &completed, int i) {
        if(completed[i]) return true;
        if(visited[i]) return false;
        visited[i] = true;
        bool isPossible{true};
        for(int &itr: adj[i]) {
            if(!solution1Helper(n, adj, ans, visited, completed, itr)) {
                isPossible = false;
                break;
            }
        }
        ans.push_back(i);
        completed[i] = true;
        visited[i] = false;
        return isPossible;
    }
    vector<int> solution1(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> completed(numCourses, false), visited(numCourses, false);
        vector<vector<int>> adj(numCourses);
        for(vector<int> &itr: prerequisites) {
            adj[itr[0]].push_back(itr[1]);
        }
        vector<int> ans;
        for(int i{0};i<numCourses;++i) {
            if(!completed[i] && !solution1Helper(numCourses, adj, ans, visited, completed, i)) {
                return {};
            }
        }
        return ans;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return solution1(numCourses, prerequisites);
    }
};