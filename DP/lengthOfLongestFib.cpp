#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int prev1, int prev2, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (dp[prev1][prev2] != -1)
            return dp[prev1][prev2];

        int count = 0;
        int idx = lower_bound(arr.begin(), arr.end(), arr[prev1] + arr[prev2]) - arr.begin();
        if (idx != arr.size() && arr[idx] == arr[prev1] + arr[prev2])
        {
            count += 1 + solve(prev2, idx, arr, dp);
        }
        return dp[prev1][prev2] = count;
    }

public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int idx = lower_bound(arr.begin(), arr.end(), arr[i] + arr[j]) - arr.begin();
                if (idx != n && arr[idx] == arr[i] + arr[j])
                {
                    ans = max(ans, 3 + solve(j, idx, arr, dp));
                }
            }
        }
        return ans;
    }
};