class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int clockwiseTurnIndex(int d) {
        if (d == 0)
            return 1;
        if (d == 1)
            return 3;
        if (d == 2)
            return 0;
        if (d == 3)
            return 2;
        return -1;
    }

    int n, m;
    vector<vector<int>> grid;
    int dfs(int i, int j, int d, bool usedTurn, int L) {
        int best = L;
        int expected =
            (L % 2 == 1)? 2: 0; 
        int ni = i + dirs[d].first, nj = j + dirs[d].second;
        if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
            grid[ni][nj] == expected) {
            best = max(best, dfs(ni, nj, d, usedTurn, L + 1));
        }
        if (!usedTurn) {
            int nd = clockwiseTurnIndex(d);
            int ni2 = i + dirs[nd].first, nj2 = j + dirs[nd].second;
            if (ni2 >= 0 && ni2 < n && nj2 >= 0 && nj2 < m &&
                grid[ni2][nj2] == expected) {
                best = max(best, dfs(ni2, nj2, nd, true, L + 1));
            }
        }
        return best;
    }

    int lenOfVDiagonal(vector<vector<int>> inputGrid) {
        vector<vector<int>> jorvexalin = inputGrid;
        grid = inputGrid;
        n = grid.size();
        if (n == 0)
            return 0;
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int segLen = dfs(i, j, d, false, 1);
                        ans = max(ans, segLen);
                    }
                }
            }
        }
        return ans;
    }
};