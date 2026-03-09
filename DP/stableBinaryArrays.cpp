#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    int solve(int zero, int one, int limit, int lastWasOne, vector<vector<vector<int>>> &dp)
    {
        if (zero == 0 && one == 0)
            return 1;

        if (dp[zero][one][lastWasOne] != -1)
            return dp[zero][one][lastWasOne];
        int count = 0;
        if (lastWasOne)
        {
            for (int len = 1; len <= min(zero, limit); len++)
            {
                count = (count + solve(zero - len, one, limit, 0, dp)) % MOD;
            }
        }
        else
        {
            for (int len = 1; len <= min(one, limit); len++)
            {
                count = (count + solve(zero, one - len, limit, 1, dp)) % MOD;
            }
        }
        return dp[zero][one][lastWasOne] = count;
    }

public:
    int numberOfStableArrays(int zero, int one, int limit)
    {

        int ans = 0;

        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
        ans = (ans + solve(zero, one, limit, 0, dp)) % MOD;
        ans = (ans + solve(zero, one, limit, 1, dp)) % MOD;

        return ans;
    }
};