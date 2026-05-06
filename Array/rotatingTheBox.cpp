#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        /*
        Step 1: Move the stones to right as long as there is empty space
        */
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == '#')
                {
                    int p = j + 1;
                    while (p < n && grid[i][p] == '.')
                    {
                        p++;
                    }
                    grid[i][j] = '.';
                    grid[i][p - 1] = '#';
                }
            }
        }
        /*
        Step 2: Transpose the Matrix
        */
        vector<vector<char>> result(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[j][i] = grid[i][j];
            }
        }
        /*
        Step 3: Reverse the rows
        */
        for (auto &it : result)
        {
            reverse(it.begin(), it.end());
        }
        return result;
    }
};