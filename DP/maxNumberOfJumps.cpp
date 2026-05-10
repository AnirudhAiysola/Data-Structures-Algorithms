#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, vector<int> &nums, int &target, vector<int> &dp)
    {
        if (index == nums.size() - 1)
            return 0;

        if (dp[index] != -1)
            return dp[index];
        int ans = -1e9;
        for (int i = index; i < nums.size(); i++)
        {
            if (abs(nums[i] - nums[index]) <= target && i != index)
            {
                ans = max(ans, 1 + solve(i, nums, target, dp));
            }
        }
        return dp[index] = ans;
    }

public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> dp(n + 1, -1);
        int ans = solve(0, nums, target, dp);

        return ans < 0 ? -1 : ans;
    }
};