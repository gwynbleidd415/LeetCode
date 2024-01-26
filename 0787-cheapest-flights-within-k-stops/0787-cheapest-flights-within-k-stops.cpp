class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> &flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> pr(n, INT_MAX);
        pr[src] = 0;
        queue<pair<int, int>> qu;
        qu.push({src, 0});
        pair<int, int> front;
        int ck{0}, sz;
        while(!qu.empty() && ck <= k) {
            sz = qu.size();
            for(int i{0};i<sz;++i) {
                front = qu.front(), qu.pop();
                for(pair<int, int> &itr: adj[front.first]) {
                    if(pr[itr.first] > itr.second + front.second) {
                        pr[itr.first] = itr.second + front.second;
                        qu.push({itr.first, itr.second + front.second});
                    }
                }
            }
            ++ck;
        }
        return pr[dst] == INT_MAX ? -1 : pr[dst];
    }
};