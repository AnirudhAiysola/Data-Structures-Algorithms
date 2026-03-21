#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int i = x, j = x + k - 1;

        while (i <= j)
        {
            for (int p = y; p < y + k; p++)
            {
                swap(grid[i][p], grid[j][p]);
            }
            i++;
            j--;
        }
        return grid;
    }
};