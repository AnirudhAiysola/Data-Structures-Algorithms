#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int prev, vector<vector<int>> &prefix, int &m, vector<vector<int>> &dp)
    {
        if (index >= prefix.size())
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];
        int ops = 1e9;

        for (int i = 0; i <= 9; i++)
        {
            if (prev != i)
            {
                int cost = m - prefix[index][i];
                ops = min(ops, cost + solve(index + 1, i, prefix, m, dp));
            }
        }
        return dp[index][prev + 1] = ops;
    }

public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prefix(n, vector<int>(10, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i][grid[j][i]]++;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(12, -1));
        return solve(0, -1, prefix, m, dp);
    }
};