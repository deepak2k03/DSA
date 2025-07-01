struct choice {
    char dname;
    int dx, dy;
};

bool isSolved(int x, int y, int n) {
    return x == n - 1 && y == n - 1;
}

bool isValid(int x, int y, int n, vector<vector<int>>& maze) {
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1;
}

void solve(int x, int y, int n, vector<string>& res, string& path,
           vector<vector<int>>& maze, vector<choice>& choices) {
    if (isSolved(x, y, n)) {
        res.push_back(path);
        return;
    }

    maze[x][y] = 0;  // ✅ Mark current as visited

    for (auto& choice : choices) {
        int newX = x + choice.dx;
        int newY = y + choice.dy;
        if (isValid(newX, newY, n, maze)) {
            path.push_back(choice.dname);
            solve(newX, newY, n, res, path, maze, choices);
            path.pop_back();
        }
    }

    maze[x][y] = 1;  // ✅ Unmark current on backtrack
}

class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> res;
        string path = "";
        vector<choice> choices = {
            {'D', 1, 0}, {'L', 0, -1}, {'R', 0, 1}, {'U', -1, 0}
        };
        if (maze[0][0] == 1)
            solve(0, 0, n, res, path, maze, choices);
        sort(res.begin(), res.end()); // optional
        return res;
    }
};
