class Solution {
private:
    int solution1Helper(vector<vector<int>> &adj, vector<vector<int>> &ans, vector<int> &disc, vector<int> &low, int &time, int index, int par) {
        if(disc[index] != 0) return low[index];
        low[index] = disc[index] = ++time;
        int cLow;
        for(int i: adj[index]) {
            if(i == par) continue;
            cLow = solution1Helper(adj, ans, disc, low, time, i, index);
            if(cLow > disc[index]) ans.push_back({index, i});
            low[index] = min(low[index], cLow);
        }
        return low[index];
    }
    vector<vector<int>> solution1(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(vector<int> &edge: connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> disc(n), low(n);
        int time{0};
        vector<vector<int>> ans;
        solution1Helper(adj, ans, disc, low, time, 0, -1);
        return ans;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        return solution1(n, connections);
    }
};
