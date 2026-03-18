#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSum(int r1, int c1, int r2, int c2, vector<vector<int>> &prefixSum)
    {
        int sum = prefixSum[r2][c2];
        if (r1 - 1 >= 0)
            sum -= prefixSum[r1 - 1][c2];
        if (c1 - 1 >= 0)
            sum -= prefixSum[r2][c1 - 1];
        if (r1 - 1 >= 0 && c1 - 1 >= 0)
            sum += prefixSum[r1 - 1][c1 - 1];

        return sum;
    }

public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prefixSum(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                prefixSum[i][j] = grid[i][j];
                if (i - 1 >= 0)
                    prefixSum[i][j] += prefixSum[i - 1][j];
                if (j - 1 >= 0)
                    prefixSum[i][j] += prefixSum[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0)
                    prefixSum[i][j] -= prefixSum[i - 1][j - 1];
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (getSum(0, 0, i, j, prefixSum) <= k)
                    ans++;
            }
        }
        return ans;
    }
};