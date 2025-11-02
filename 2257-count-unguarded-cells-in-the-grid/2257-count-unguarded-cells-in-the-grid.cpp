class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0 = empty

        // Mark guards as 2 and walls as 3
        for (auto& g : guards)
            grid[g[0]][g[1]] = 2;
        for (auto& w : walls)
            grid[w[0]][w[1]] = 3;

        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // For each guard
        for (auto& g : guards) {
            int x = g[0], y = g[1];
            for (auto [dx, dy] : dirs) {
                int i = x + dx, j = y + dy;
                while (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != 3 &&
                       grid[i][j] != 2) {
                    // mark as guarded if empty
                    if (grid[i][j] == 0)
                        grid[i][j] = 1;
                    i += dx;
                    j += dy;
                }
            }
        }

        // Count unguarded empty cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};