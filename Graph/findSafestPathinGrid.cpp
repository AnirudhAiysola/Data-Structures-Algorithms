#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rowCoordinates = {0, -1, 0, 1};
    vector<int> colCoordinates = {1, 0, -1, 0};
    void bfs(vector<vector<int>> &dist, vector<vector<int>> &grid)
    {
        int n = dist.size();

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            auto [row, col, d] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = row + rowCoordinates[i];
                int nc = col + colCoordinates[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] == 1 || dist[nr][nc] != 1e9)
                    continue;
                dist[nr][nc] = 1 + d;
                q.push({nr, nc, 1 + d});
            }
        }
    }
    bool check(int x, vector<vector<int>> &grid, vector<vector<int>> &dist)
    {
        int n = grid.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        if (dist[0][0] < x)
            return false;

        queue<tuple<int, int>> q;
        q.push({0, 0});

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            if (row == n - 1 && col == n - 1)
                return true;
            for (int i = 0; i < 4; i++)
            {
                int nr = row + rowCoordinates[i];
                int nc = col + colCoordinates[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc] || dist[nr][nc] < x)
                    continue;
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        bfs(dist, grid);

        int low = 0, high = 900;
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, grid, dist))
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