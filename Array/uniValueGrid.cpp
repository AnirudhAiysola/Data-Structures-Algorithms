#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> nums;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (abs(nums[i] - nums[i + 1]) % x != 0)
                return -1;
        }

        int ops = 0;
        int t = nums[nums.size() / 2];

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = abs(t - nums[i]);
            ops += diff / x;
        }
        return ops;
    }
};