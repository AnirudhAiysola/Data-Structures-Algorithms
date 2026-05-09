#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotateLeft(vector<int> &data, int k)
    {
        int n = data.size();
        k = k % n;

        reverse(data.begin(), data.begin() + k);
        reverse(data.begin() + k, data.end());
        reverse(data.begin(), data.end());
    }
    void insertData(vector<vector<int>> &result, int a, int b, int c, int d,
                    vector<int> &data)
    {
        int m = result.size();
        int n = result[0].size();

        int p = 0;
        for (int i = c; i <= d; i++)
        {
            result[a][i] = data[p];
            p++;
        }
        a++;
        for (int i = a; i <= b; i++)
        {
            result[i][d] = data[p];
            p++;
        }
        d--;
        for (int i = d; i >= c; i--)
        {
            result[b][i] = data[p];
            p++;
        }
        b--;
        for (int i = b; i >= a; i--)
        {
            result[i][c] = data[p];
            p++;
        }
        c++;
    }

public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int layers = n / 2;

        vector<vector<int>> result(m, vector<int>(n, 0));

        int top = 0, left = 0, right = n - 1, bottom = m - 1;

        while (top <= bottom && left <= right)
        {
            /*
            Left to Right
            Top to Bottom
            Right to Left
            Bottom to Top
            */
            int a = top, b = bottom, c = left, d = right;
            vector<int> data;
            for (int i = c; i <= d; i++)
            {
                data.push_back(grid[a][i]);
            }
            a++;
            for (int i = a; i <= b; i++)
            {
                data.push_back(grid[i][d]);
            }
            d--;
            for (int i = d; i >= c; i--)
            {
                data.push_back(grid[b][i]);
            }
            b--;
            for (int i = b; i >= a; i--)
            {
                data.push_back(grid[i][c]);
            }
            c++;

            rotateLeft(data, k);
            insertData(result, top, bottom, left, right, data);
            top++;
            right--;
            bottom--;
            left++;
        }
        return result;
    }
};