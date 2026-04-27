
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        if (vis[i][j])
            return false;

        int m = grid.size();
        int n = grid[0].size();

        if (i == m - 1 && j == n - 1)
            return true;

        vis[i][j] = 1;

        int val = grid[i][j];

        if (val == 1)
        {
            if (j + 1 < n && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5))
            {
                if (solve(i, j + 1, grid, vis))
                    return true;
            }
            if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
            {
                if (solve(i, j - 1, grid, vis))
                    return true;
            }
        }
        if (val == 2)
        {
            if (i - 1 >= 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4))
            {
                if (solve(i - 1, j, grid, vis))
                    return true;
            }
            if (i + 1 < m && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6))
            {
                if (solve(i + 1, j, grid, vis))
                    return true;
            }
        }
        if (val == 3)
        {
            if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
            {
                if (solve(i, j - 1, grid, vis))
                    return true;
            }
            if (i + 1 < m && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6))
            {
                if (solve(i + 1, j, grid, vis))
                    return true;
            }
        }
        if (val == 4)
        {
            if (j + 1 < n && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5))
            {
                if (solve(i, j + 1, grid, vis))
                    return true;
            }
            if (i + 1 < m && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6))
            {
                if (solve(i + 1, j, grid, vis))
                    return true;
            }
        }
        if (val == 5)
        {
            if (i - 1 >= 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4))
            {
                if (solve(i - 1, j, grid, vis))
                    return true;
            }
            if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
            {
                if (solve(i, j - 1, grid, vis))
                    return true;
            }
        }
        if (val == 6)
        {
            if (j + 1 < n && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5))
            {
                if (solve(i, j + 1, grid, vis))
                    return true;
            }
            if (i - 1 >= 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4))
            {
                if (solve(i - 1, j, grid, vis))
                    return true;
            }
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        return solve(0, 0, grid, vis);
    }
};