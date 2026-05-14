#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, string &s, string &p,
              vector<int> &canRemove,
              vector<vector<int>> &dp)
    {

        int n = s.size();
        int m = p.size();

        // pattern fully matched
        if (j == m)
        {
            int cnt = 0;
            for (int k = i; k < n; k++)
            {
                cnt += canRemove[k];
            }
            return cnt;
        }

        // source exhausted but pattern not matched
        if (i == n)
            return -1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = -1e9;

        if (s[i] == p[j])
        {
            ans = max(ans, solve(i + 1, j + 1, s, p, canRemove, dp));
        }

        if (canRemove[i])
        {
            ans = max(ans, 1 + solve(i + 1, j, s, p, canRemove, dp));
        }
        else
        {
            ans = max(ans, solve(i + 1, j, s, p, canRemove, dp));
        }

        return dp[i][j] = ans;
    }

    int maxRemovals(string source, string pattern,
                    vector<int> &targetIndices)
    {

        int n = source.size();
        int m = pattern.size();

        vector<int> canRemove(n, 0);

        for (int idx : targetIndices)
        {
            canRemove[idx] = 1;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(0, 0, source, pattern, canRemove, dp);
    }
};