#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, string &s, vector<vector<bool>> &dp, vector<int> &cache)
    {
        if (index >= s.size())
            return 0;
        if (dp[index][s.size() - 1])
            return 0;

        if (cache[index] != -1)
            return cache[index];
        int ans = INT_MAX;
        for (int i = index; i < s.size(); i++)
        {
            if (dp[index][i])
            {
                ans = min(ans, 1 + solve(i + 1, s, dp, cache));
            }
        }
        return cache[index] = ans;
    }

public:
    int minCut(string s)
    {
        int n = s.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
            }
        }
        vector<int> cache(n + 1, -1);
        return solve(0, s, dp, cache);
    }
};