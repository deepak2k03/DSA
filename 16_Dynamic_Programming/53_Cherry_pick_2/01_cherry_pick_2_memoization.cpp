class Solution {
  public:
    int f(int row, int col1, int col2, vector<vector<int>>& grid,
           vector<vector<vector<int>>>& dp) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) {
            return -1e9;
        }
        if (row == rows - 1) {
            return grid[row][col1] + (col1 == col2 ? 0 : grid[row][col2]);
        }
        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int best = -1e9;
        for (int move1 = -1; move1 <= 1; move1++) {
            for (int move2 = -1; move2 <= 1; move2++) {
                best = max(best, f(row + 1, col1 + move1, col2 + move2,
                                   grid, dp));
            }
        }

        int cherries = grid[row][col1];
        if (col1 != col2) cherries += grid[row][col2];
        return dp[row][col1][col2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return f(0, 0, cols - 1, grid, dp);
    }
};
