#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    void getPrefixCounts(vector<string> &pizza, vector<vector<int>> &prefix)
    {
        int m = prefix.size();
        int n = prefix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                prefix[i][j] = (pizza[i][j] == 'A');
                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    int query(vector<vector<int>> &prefix, int r1, int r2, int c1, int c2)
    {
        int val = prefix[r2][c2];
        if (r1 > 0)
            val -= prefix[r1 - 1][c2];
        if (c1 > 0)
            val -= prefix[r2][c1 - 1];
        if (r1 > 0 && c1 > 0)
            val += prefix[r1 - 1][c1 - 1];
        return val;
    }
    const int MOD = 1e9 + 7;
    ll solve(int row, int col, int k, vector<string> &pizza,
             vector<vector<int>> &prefix, vector<vector<vector<ll>>> &dp)
    {
        int m = pizza.size(), n = pizza[0].size();
        if (k == 0)
        {
            return query(prefix, row, m - 1, col, n - 1) > 0;
        }

        if (dp[row][col][k] != -1)
            return dp[row][col][k];

        ll rowCut = 0, colCut = 0;

        for (int i = row; i < m - 1; i++)
        {
            int r1 = query(prefix, row, i, col, n - 1);

            int r2 = query(prefix, i + 1, m - 1, col, n - 1);

            if (r1 > 0 && r2 > 0)
            {
                rowCut =
                    (rowCut + solve(i + 1, col, k - 1, pizza, prefix, dp)) %
                    MOD;
            }
        }
        for (int i = col; i < n - 1; i++)
        {
            int c1 = query(prefix, row, m - 1, col, i);

            int c2 = query(prefix, row, m - 1, i + 1, n - 1);

            if (c1 > 0 && c2 > 0)
            {
                colCut = (colCut + solve(row, i + 1, k - 1, pizza, prefix, dp));
            }
        }
        return dp[row][col][k] = (rowCut + colCut) % MOD;
    }

public:
    int ways(vector<string> &pizza, int k)
    {
        int m = pizza.size();
        int n = pizza[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));

        getPrefixCounts(pizza, prefix);

        k--;
        vector<vector<vector<ll>>> dp(
            m + 1, vector<vector<ll>>(n + 1, vector<ll>(k + 1, -1)));
        return solve(0, 0, k, pizza, prefix, dp);
    }
};