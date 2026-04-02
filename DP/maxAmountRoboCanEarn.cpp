#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, int k, vector<vector<int>> &grid,
              vector<vector<vector<int>>> &dp)
    {
        if (i >= grid.size() || j >= grid[0].size())
            return -1e9;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            if (grid[i][j] < 0)
            {
                return k > 0 ? 0 : grid[i][j];
            }
            return grid[i][j];
        }

        if (dp[i][j][k] != INT_MIN)
            return dp[i][j][k];

        int down = -1e9;
        if (grid[i][j] >= 0)
        {
            down = grid[i][j] + solve(i + 1, j, k, grid, dp);
        }
        else
        {
            if (k > 0)
                down =
                    max(solve(i + 1, j, k - 1, grid, dp),         // skip
                        grid[i][j] + solve(i + 1, j, k, grid, dp) // don't skip
                    );
            else
                down = grid[i][j] + solve(i + 1, j, k, grid, dp);
        }

        int right = -1e9;
        if (grid[i][j] >= 0)
        {
            right = grid[i][j] + solve(i, j + 1, k, grid, dp);
        }
        else
        {
            if (k > 0)
                right = max(solve(i, j + 1, k - 1, grid, dp),
                            grid[i][j] + solve(i, j + 1, k, grid, dp));
            else
                right = grid[i][j] + solve(i, j + 1, k, grid, dp);
        }
        return dp[i][j][k] = max(down, right);
    }

public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int m = coins.size();
        int n = coins[0].size();

        int k = 2;

        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, INT_MIN)));
        return solve(0, 0, k, coins, dp);
    }
};