#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int x, int index, vector<vector<int>> &queries, int k, int p, vector<vector<int>> &dp)
    {
        if (x == 0)
            return true;
        if (index == k)
            return false;

        if (dp[x][index] != -1)
            return dp[x][index];
        bool notPick = solve(x, index + 1, queries, k, p, dp);
        bool pick = false;
        if (queries[index][0] <= p && p <= queries[index][1] && x - queries[index][2] >= 0)
        {
            pick = solve(x - queries[index][2], index + 1, queries, k, p, dp);
        }

        return dp[x][index] = pick || notPick;
    }

public:
    bool check(int k, vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();

        /*
        Does first K queries cover all the indices, and the Values can make the nums equal to zero
        */
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> dp(nums[i] + 1, vector<int>(k + 1, -1));
            if (!solve(nums[i], 0, queries, k, i, dp))
                return false;
        }
        return true;
    }

public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();

        int low = 0, high = q;
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, nums, queries))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};