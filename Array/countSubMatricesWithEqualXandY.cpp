#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> getCount(int r1, int c1, int r2, int c2, vector<vector<pair<int, int>>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        pair<int, int> p = grid[r2][c2];
        if (r1 - 1 >= 0)
        {
            p.first -= grid[r1 - 1][c2].first;
            p.second -= grid[r1 - 1][c2].second;
        }
        if (c1 - 1 >= 0)
        {
            p.first -= grid[r2][c1 - 1].first;
            p.second -= grid[r2][c1 - 1].second;
        }
        if (r1 - 1 >= 0 && c1 - 1 >= 0)
        {
            p.first += grid[r1 - 1][c1 - 1].first;
            p.second += grid[r1 - 1][c1 - 1].second;
        }
        return p;
    }

public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int, int>>> prefix(m, vector<pair<int, int>>(n, {0, 0}));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'X')
                {
                    prefix[i][j] = {1, 0};
                }
                else if (grid[i][j] == 'Y')
                {
                    prefix[i][j] = {0, 1};
                }
                if (i - 1 >= 0)
                {
                    prefix[i][j].first += prefix[i - 1][j].first;
                    prefix[i][j].second += prefix[i - 1][j].second;
                }
                if (j - 1 >= 0)
                {
                    prefix[i][j].first += prefix[i][j - 1].first;
                    prefix[i][j].second += prefix[i][j - 1].second;
                }
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    prefix[i][j].first -= prefix[i - 1][j - 1].first;
                    prefix[i][j].second -= prefix[i - 1][j - 1].second;
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto [x, y] = getCount(0, 0, i, j, prefix);
                if (x > 0 && x == y)
                    ans++;
            }
        }
        return ans;
    }
};