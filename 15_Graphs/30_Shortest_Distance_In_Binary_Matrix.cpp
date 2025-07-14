class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If start or end is blocked
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        // BFS setup
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        dist[0][0] = 1;  // Starting cell counts as 1 step
        q.push({0, 0});
        
        // 8 directions
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // If we reach the destination
            if(x == n-1 && y == n-1) return dist[x][y];

            for(int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Check bounds and if walkable and unvisited or shorter path
                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   grid[nx][ny] == 0 && dist[x][y] + 1 < dist[nx][ny]) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1; // No path found
    }
};
