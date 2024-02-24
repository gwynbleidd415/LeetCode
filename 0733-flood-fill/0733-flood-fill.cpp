class Solution {
private:
    void solution1Helper(vector<vector<int>>& image, int sr, int sc, int color, int scolor) {
        if(sr < 0 || sc < 0 || sr == image.size() || sc == image.front().size() || image[sr][sc] != scolor) return;
        image[sr][sc] = color;
        solution1Helper(image, sr+1, sc, color, scolor);
        solution1Helper(image, sr-1, sc, color, scolor);
        solution1Helper(image, sr, sc+1, color, scolor);
        solution1Helper(image, sr, sc-1, color, scolor);
    }
    vector<vector<int>> solution1(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color != image[sr][sc]) solution1Helper(image, sr, sc, color, image[sr][sc]);
        return image;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        return solution1(image, sr, sc, color);
    }
};
