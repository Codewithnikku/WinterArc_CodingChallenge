class MinimumXORPathInGrid {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> dp(n, vector<char>(1024, 0));
        
        dp[0][grid[0][0]] = 1;

        for (int j = 1; j < n; j++)
            dp[j][grid[0][j] ^ grid[0][j - 1]] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                vector<char> cur(1024, 0);
                int v = grid[i][j];

                if (i > 0) {
                    for (int x = 0; x < 1024; x++)
                        if (dp[j][x])
                            cur[x ^ v] = 1;
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; x++)
                        if (dp[j - 1][x])
                            cur[x ^ v] = 1;
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < 1024; x++)
            if (dp[n - 1][x])
                return x;

        return 0;
    }
};