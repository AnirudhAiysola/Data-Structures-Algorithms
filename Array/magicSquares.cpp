#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Finds the number of 3x3 magic squares in a given grid.
 * 
 * A magic square is a 3x3 subgrid where:
 * - All rows have the same sum
 * - All columns have the same sum
 * - Both diagonals have the same sum
 * - All elements are distinct integers between 1 and 9 (inclusive)
 */

/**
 * @brief Checks if a 3x3 subgrid starting at (row, col) is a magic square.
 * 
 * @param grid The 2D vector representing the grid
 * @param row The starting row index of the 3x3 subgrid
 * @param col The starting column index of the 3x3 subgrid
 * 
 * @return true if the 3x3 subgrid is a magic square, false otherwise
 * 
 * @details This function verifies:
 *          - All three rows have equal sums
 *          - All three columns have equal sums
 *          - All elements are in range [1, 9]
 *          - All elements are unique
 *          - Both diagonals match the row/column sums
 */

/**
 * @brief Counts the total number of 3x3 magic squares in the grid.
 * 
 * @param grid The 2D vector representing the grid
 * 
 * @return The count of all valid 3x3 magic square subgrids
 * 
 * @details Iterates through all possible 3x3 subgrids in the given grid
 *          and counts those that satisfy the magic square conditions.
 */
class Solution
{
public:
    bool isMagic(vector<vector<int>> &grid, int row, int col)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 3 row sum
        int r1 = 0, r2 = 0, r3 = 0;
        for (int i = col; i < col + 3; i++)
            r1 += grid[row][i];
        for (int i = col; i < col + 3; i++)
            r2 += grid[row + 1][i];
        for (int i = col; i < col + 3; i++)
            r3 += grid[row + 2][i];

        if (r1 != r2 || r1 != r3 || r2 != r3)
            return false;

        // 3 col sum
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = row; i < row + 3; i++)
            c1 += grid[i][col];
        for (int i = row; i < row + 3; i++)
            c2 += grid[i][col + 1];
        for (int i = row; i < row + 3; i++)
            c3 += grid[i][col + 2];

        if (c1 != c2 || c2 != c3 || c1 != c3)
            return false;

        vector<int> vis(10, 0);

        for (int i = row; i < row + 3; i++)
        {
            for (int j = col; j < col + 3; j++)
            {
                if (grid[i][j] > 9 || grid[i][j] < 1)
                    return false;
                if (vis[grid[i][j]])
                    return false;
                vis[grid[i][j]] = 1;
            }
        }
        int d1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int d2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];

        if (d1 != r1 || d2 != r2)
            return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i <= m - 3; i++)
        {
            for (int j = 0; j <= n - 3; j++)
            {
                if (isMagic(grid, i, j))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};