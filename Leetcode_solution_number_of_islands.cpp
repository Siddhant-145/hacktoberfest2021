//BFS approach

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = 0;

    auto bfs = [&](int r, int c) {
      queue<pair<int, int>> q{{{r, c}}};
      grid[r][c] = '2';  // Mark '2' as visited
      while (!q.empty()) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] != '1')
            continue;
          q.emplace(x, y);
          grid[x][y] = '2';  // Mark '2' as visited
        }
      }
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == '1') {
          bfs(i, j);
          ++ans;
        }

    return ans;
  }
};


//DFS Approach

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ++ans;
        }

    return ans;
  }

 private:
  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] != '1')
      return;

    grid[i][j] = '2';  // Mark '2' as visited
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
};
