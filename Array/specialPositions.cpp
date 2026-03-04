#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Finds the number of special positions in a binary matrix.
 * 
 * A special position is defined as a cell containing 1 that is the only 1 
 * in its row and the only 1 in its column.
 */

/**
 * @brief Counts the number of special positions in a binary matrix.
 * 
 * @param mat A 2D vector representing a binary matrix where each element 
 *            is either 0 or 1.
 * 
 * @return The number of special positions in the matrix, where a special 
 *         position contains a 1 that is the only 1 in its row and column.
 * 
 * @complexity Time: O(m * n) where m is the number of rows and n is the 
 *             number of columns. The algorithm performs two passes through 
 *             the matrix.
 *             Space: O(m + n) for storing row and column counts.
 * 
 * @algorithm
 * 1. Count the number of 1s in each row and column.
 * 2. Iterate through the matrix again and count cells with value 1 where 
 *    both the row count and column count are exactly 1.
 */
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rows(m, 0), cols(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (rows[i] == 1 && cols[j] == 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};