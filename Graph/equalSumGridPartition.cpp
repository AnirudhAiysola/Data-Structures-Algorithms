#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    pair<ll, ll> getSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum1 += grid[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum2 += grid[j][i];
            }
        }
        return {sum1, sum2};
    }

public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        auto [sum1, sum2] = getSum(grid);

        ll curr = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                curr += grid[i][j];
            }
            if (curr == sum1 - curr)
                return true;
        }
        curr = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                curr += grid[j][i];
            }
            if (curr == sum2 - curr)
                return true;
        }
        return false;
    }
};