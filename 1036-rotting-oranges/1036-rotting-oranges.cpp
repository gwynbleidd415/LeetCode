class Solution {
    int solution1(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid.front().size();
        queue<pair<int, int>> qu;
        int fc{0};
        for(int i{0};i<n;++i) {
            for(int j{0};j<m;++j) {
                if(grid[i][j] == 2) qu.push({i, j});
                else if(grid[i][j] == 1) ++fc;
            }
        }
        if(fc == 0) return 0;
        int ans{-1}, qsz;
        pair<int, int> front;
        while(!qu.empty()) {
            ++ans;
            qsz = qu.size();
            for(int i{0};i<qsz;++i) {
                front = qu.front(), qu.pop();
                if(front.first > 0 && grid[front.first-1][front.second] == 1) {
                    qu.push({front.first-1, front.second});
                    grid[front.first-1][front.second] = 2;
                    --fc;
                }
                if(front.second > 0 && grid[front.first][front.second-1] == 1) {
                    qu.push({front.first, front.second - 1});
                    grid[front.first][front.second-1] = 2;
                    --fc;
                }
                if(front.first+1<n && grid[front.first+1][front.second] == 1) {
                    qu.push({front.first+1, front.second});
                    grid[front.first+1][front.second] = 2;
                    --fc;
                }
                if(front.second+1 <m && grid[front.first][front.second+1] == 1) {
                    qu.push({front.first, front.second+1});
                    grid[front.first][front.second+1] = 2;
                    --fc;
                }
            }
        }
        if(fc == 0) return ans;
        return -1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return solution1(grid);
    }
};