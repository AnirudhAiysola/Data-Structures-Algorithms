#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve1(int i, int j, vector<vector<int>> &grid,
               vector<vector<int>> &dp)
    {

        if (grid[i][j] == 0)
            return dp[i][j] = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int m = grid.size();
        int n = grid[0].size();

        int ans = 1;

        if (i + 1 < m && j - 1 >= 0 && j + 1 < n &&
            grid[i + 1][j] &&
            grid[i + 1][j - 1] &&
            grid[i + 1][j + 1])
        {

            ans = 1 + min({solve1(i + 1, j, grid, dp),
                           solve1(i + 1, j - 1, grid, dp),
                           solve1(i + 1, j + 1, grid, dp)});
        }

        return dp[i][j] = ans;
    }

    int solve2(int i, int j, vector<vector<int>> &grid,
               vector<vector<int>> &dp)
    {

        if (grid[i][j] == 0)
            return dp[i][j] = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int m = grid.size();
        int n = grid[0].size();

        int ans = 1;

        if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < n &&
            grid[i - 1][j] &&
            grid[i - 1][j - 1] &&
            grid[i - 1][j + 1])
        {

            ans = 1 + min({solve2(i - 1, j, grid, dp),
                           solve2(i - 1, j - 1, grid, dp),
                           solve2(i - 1, j + 1, grid, dp)});
        }

        return dp[i][j] = ans;
    }

    int countPyramids(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp1(m, vector<int>(n, -1));
        vector<vector<int>> dp2(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    ans += solve1(i, j, grid, dp1) - 1;

        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                if (grid[i][j])
                    ans += solve2(i, j, grid, dp2) - 1;

        return ans;
    }
};