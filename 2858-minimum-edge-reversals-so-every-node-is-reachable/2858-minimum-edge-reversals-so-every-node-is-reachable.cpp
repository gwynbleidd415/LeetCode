class Solution {
private:
    int dfs(int root, int par, int depth, int edgeReversals, vector<int> &ans, vector<vector<pair<int, int>>> &adjList) {
        ans[root] = depth - 2*edgeReversals;
        int ans1 = 0;
        for(auto &adj: adjList[root]) {
            if(adj.first == par) continue;
            ans1 += dfs(adj.first, root, depth+1, edgeReversals + adj.second, ans, adjList) + adj.second;
        }
        return ans1;
    }
    vector<int> solution1(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(n);
        for(vector<int> &edge: edges) {
            adjList[edge[0]].push_back({edge[1], 0});
            adjList[edge[1]].push_back({edge[0], 1});
        }
        vector<int> ans(n);
        ans.front() = dfs(0, 0, 0, 0, ans, adjList);
        for(int i{1};i<n;++i) ans[i] += ans.front();
        return ans;
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        return solution1(n, edges);
    }
};