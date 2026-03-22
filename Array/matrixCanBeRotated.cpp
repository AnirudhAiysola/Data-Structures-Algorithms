#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        /*
        [1,2,3]       1,4,7. 147
        [4,5,6]       2,5,6.  258
        [7,8,9]       3,8,9.  369
        */
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(grid[i][j], grid[j][i]);
            }
        }
        for (auto &it : grid)
        {
            reverse(it.begin(), it.end());
        }
        return grid;
    }

public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int n = mat.size();

        int count = 4;

        while (count--)
        {
            mat = transpose(mat);
            if (mat == target)
                return true;
        }
        return false;
    }
};