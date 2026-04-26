#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int k, vector<vector<int>> &grid)
    {
        if (grid[0][0] < k)
            return false;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCoordinates = {0, -1, 0, 1};
        vector<int> colCoordinates = {1, 0, -1, 0};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, grid[0][0]});
        vis[0][0] = 1;

        while (!q.empty())
        {
            auto [row, col, mn] = q.front();
            q.pop();

            if (row == m - 1 && col == n - 1)
            {
                if (mn >= k)
                    return true;
            }
            if (mn < k)
                continue;

            for (int i = 0; i < 4; i++)
            {
                int nr = row + rowCoordinates[i];
                int nc = col + colCoordinates[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc])
                    continue;
                vis[nr][nc] = 1;
                int newMn = min(mn, grid[nr][nc]);
                q.push({nr, nc, newMn});
            }
        }
        return false;
    }

public:
    int maximumMinimumPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int low = INT_MAX, high = INT_MIN;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                low = min(low, grid[i][j]);
                high = max(high, grid[i][j]);
            }
        }

        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (solve(mid, grid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};