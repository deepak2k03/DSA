class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>& image, 
             int initialColor, int newColor, int drow[], int dcol[]) {
        
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, initialColor, newColor, drow, dcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor = image[sr][sc];
        if (initialColor == newColor) return image;
        
        vector<vector<int>> ans = image;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        
        dfs(sr, sc, ans, image, initialColor, newColor, drow, dcol);
        return ans;
    }
};
