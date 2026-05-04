#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, vector<int> &nums, int &k, int p1, int p2,
              vector<vector<vector<int>>> &dp)
    {
        if (index >= nums.size())
            return 0;
        if (p1 == 0 && p2 == 0)
        {
            int sum = accumulate(nums.begin() + index, nums.end(), 0);
            return sum;
        }
        if (dp[index][p1][p2] != -1)
            return dp[index][p1][p2];

        int notPick = nums[index] + solve(index + 1, nums, k, p1, p2, dp);

        int sub = INT_MAX;
        if (p2 > 0 && nums[index] >= k)
        {
            sub = (nums[index] - k) + solve(index + 1, nums, k, p1, p2 - 1, dp);
        }

        int div = INT_MAX;
        if (p1 > 0)
        {
            int val = (nums[index] + 1) / 2;
            div = val + solve(index + 1, nums, k, p1 - 1, p2, dp);
        }

        int subDiv = INT_MAX;
        if (p1 > 0 && p2 > 0 && nums[index] >= k)
        {
            int temp = nums[index] - k;
            temp = (temp + 1) / 2;
            subDiv = temp + solve(index + 1, nums, k, p1 - 1, p2 - 1, dp);
        }

        int divSub = INT_MAX;
        if (p1 > 0 && p2 > 0)
        {
            int temp = (nums[index] + 1) / 2;
            if (temp >= k)
            {
                temp -= k;
                divSub = temp + solve(index + 1, nums, k, p1 - 1, p2 - 1, dp);
            }
        }

        return dp[index][p1][p2] = min({notPick, sub, div, subDiv, divSub});
    }

public:
    int minArraySum(vector<int> &nums, int k, int op1, int op2)
    {
        int n = nums.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return solve(0, nums, k, op1, op2, dp);
    }
};