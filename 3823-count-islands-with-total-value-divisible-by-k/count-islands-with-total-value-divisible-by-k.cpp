class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check if it's land AND hasn't been visited yet 🎯
                if (grid[i][j] != 0 && !visited[i][j]) {
                    long long sum = grid[i][j];
                    visited[i][j] = true;
                    q.push({i, j});

                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        // Renamed loop variable from k to d
                        for (int d = 0; d < 4; d++) {
                            int nr = r + row[d];
                            int nc = c + col[d];

                            if (isValid(nr, nc, n, m) && grid[nr][nc] != 0 && !visited[nr][nc]) {
                                sum += grid[nr][nc];
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (sum % k == 0) count++;
                }
            }
        }

        return count;
    }
};