#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, int k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return 0;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int down = -1e9, right = -1e9;
        if (i + 1 < grid.size() && k - (grid[i + 1][j] > 0 ? 1 : 0) >= 0)
        {
            int newK = k - (grid[i + 1][j] > 0 ? 1 : 0);
            down = grid[i + 1][j] + solve(i + 1, j, newK, grid, dp);
        }
        if (j + 1 < grid[0].size() && k - (grid[i][j + 1] > 0 ? 1 : 0) >= 0)
        {
            int newK = k - (grid[i][j + 1] > 0 ? 1 : 0);
            right = grid[i][j + 1] + solve(i, j + 1, newK, grid, dp);
        }

        return dp[i][j][k] = max(down, right);
    }

public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        int ans = solve(0, 0, k, grid, dp);

        return ans < 0 ? -1 : ans;
    }
};