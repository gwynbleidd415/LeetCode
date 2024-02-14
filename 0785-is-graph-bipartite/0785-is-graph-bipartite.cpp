class Solution {
private:
    bool solution1(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> col(n), marked(n);
        for(int i{0};i<n;++i) {
            if(marked[i]) continue;
            queue<int> qu;
            qu.push(i), marked[i] = true;
            while(!qu.empty()) {
                int front = qu.front(); qu.pop();
                for(int adj: graph[front]) {
                    if(marked[adj]) {
                        if(col[adj] == col[front]) return false;
                        continue;
                    }
                    col[adj] = !col[front];
                    marked[adj] = true;
                    qu.push(adj);
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        return solution1(graph);
    }
};