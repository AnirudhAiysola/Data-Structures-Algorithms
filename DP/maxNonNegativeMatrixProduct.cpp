#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    pair<ll, ll> solve(int i, int j, vector<vector<int>> &grid, vector<vector<pair<ll, ll>>> &dp)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return {grid[i][j], grid[i][j]};
        }

        if (dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX))
            return dp[i][j];
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if (i + 1 < grid.size())
        {
            auto [downMax, downMin] = solve(i + 1, j, grid, dp);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }
        if (j + 1 < grid[0].size())
        {
            auto [rightMax, rightMin] = solve(i, j + 1, grid, dp);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }
        return dp[i][j] = {maxVal, minVal};
    }

public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<ll, ll>>> dp(m + 1, vector<pair<ll, ll>>(n + 1, {LLONG_MIN, LLONG_MAX}));
        auto [maxVal, minVal] = solve(0, 0, grid, dp);

        return maxVal < 0 ? -1 : maxVal % MOD;
    }
};