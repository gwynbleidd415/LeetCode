class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int w{0}, x{(int)matrix.size()-1}, z{(int)matrix.front().size()-1};
        int an{(x+1)*(z+1)};
        vector<int> ans(an);
        ans[0] = matrix.front().front();
        int i{0}, j{1};
        if(matrix.front().size() == 1){
            j = 0, i = 1;
        }
        for(int k{1};k<an;++k){
            if(i == w && j!=w) {
                if(j<z) ans[k] = matrix[i][j++];
                else ans[k] = matrix[i++][j];
            } else if(j == z) {
                if(i<x) ans[k] = matrix[i++][j];
                else ans[k] = matrix[i][j--];
            } else if(i == x) {
                if(j>w) ans[k] = matrix[i][j--];
                else ans[k] = matrix[i--][j];
            } else {
                if(i>w) ans[k] = matrix[i--][j];
                else {
                    ans[k] = matrix[++i][++j];
                    ++w, --x, --z;
                    if(j == z) ++i;
                    else ++j;
                }
            }
        }
        return ans;
        // int w{0}, x{(int)matrix.size()-1}, z{(int)matrix.front().size()-1};
        // vector<int> ans;
        // ans.reserve((x+1)*(z+1));
        // int i{-1}, j{-1};
        // while(w<x && w<z){
        //     // cout<<w<<' '<<x<<' '<<z <<' '<<i+1<<' '<<j+1<<'\n';
        //     for(++i, ++j;j<=z;++j) ans.push_back(matrix[i][j]);
        //     for(++i, --j;i<=x;++i) ans.push_back(matrix[i][j]);
        //     for(--i, --j;j>=w;--j) ans.push_back(matrix[i][j]);
        //     for(--i, ++j;i>w;--i) ans.push_back(matrix[i][j]);
        //     ++w, --x, --z;
        // }
        // if(w == x){
        //     for(++i, ++j;j<=z;++j) ans.push_back(matrix[i][j]);
        // } else if(w == z) {
        //     for(++i, ++j;i<=x;++i) ans.push_back(matrix[i][j]);
        // }
        // return ans;
    }
};