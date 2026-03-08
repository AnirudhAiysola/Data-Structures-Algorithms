#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, string &s, int &k, vector<vector<bool>> &dp, vector<int> &cache)
    {
        if (index >= s.size())
            return 0;

        if (cache[index] != -1)
            return cache[index];
        int notPick = solve(index + 1, s, k, dp, cache);

        int ans = notPick;

        for (int i = index; i < s.size(); i++)
        {
            if (dp[index][i] && i - index + 1 >= k)
            {
                ans = max(ans, 1 + solve(i + 1, s, k, dp, cache));
            }
        }
        return cache[index] = ans;
    }

public:
    int maxPalindromes(string s, int k)
    {
        int n = s.size();

        // precompute if a substring is a palindrome
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
            }
        }
        vector<int> cache(n + 1, -1);
        return solve(0, s, k, dp, cache);
    }
};