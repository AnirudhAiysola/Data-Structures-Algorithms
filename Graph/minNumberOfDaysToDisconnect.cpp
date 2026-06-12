#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;
    UnionFind(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int node)
    {
        if (parent[node] == node)
            return parent[node];
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int up = findParent(u);
        int vp = findParent(v);
        if (up == vp)
            return;

        if (size[up] <= size[vp])
        {
            parent[up] = vp;
            size[vp] += size[up];
        }
        else
        {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};
class Solution
{
public:
    bool check(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        UnionFind uf(m * n);
        vector<int> rowCoordinates = {0, -1, 0, 1};
        vector<int> colCoordinates = {1, 0, -1, 0};

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == 1)
                {
                    int id = r * n + c;
                    for (int i = 0; i < 4; i++)
                    {
                        int nr = r + rowCoordinates[i];
                        int nc = c + colCoordinates[i];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                            grid[nr][nc] == 0)
                            continue;
                        int adjId = nr * n + nc;

                        if (uf.findParent(id) != uf.findParent(adjId))
                        {
                            uf.unionBySize(id, adjId);
                        }
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int id = i * n + j;
                    if (uf.findParent(id) == id)
                        count++;
                }
            }
        }
        return count == 0 || count > 1;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (check(grid))
            return 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    if (check(grid))
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};