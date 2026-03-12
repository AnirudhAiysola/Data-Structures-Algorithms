#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        /*
        To increase the value of a number, in each row, if the first number is 0
        then we can toggle it
        */

        for (auto &it : grid)
        {
            if (it[0] == 0)
            {
                // flip
                for (int i = 0; i < it.size(); i++)
                {
                    it[i] = !it[i];
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[j][i] == 1)
                {
                    count++;
                }
            }
            int zero = m - count;
            if (zero > count)
            {
                for (int j = 0; j < m; j++)
                {
                    grid[j][i] = !grid[j][i];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            int curr = 0;

            for (int j = n - 1; j >= 0; j--)
            {
                curr = curr | (grid[i][j] << (n - j - 1));
            }

            ans += curr;
        }
        return ans;
    }
};