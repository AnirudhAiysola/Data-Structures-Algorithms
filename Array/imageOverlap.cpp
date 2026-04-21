#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOverlaps(vector<vector<int>> &A, vector<vector<int>> &B, int r, int c)
    {
        int n = A.size();

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int B_i = r + i;
                int B_j = c + j;

                if (B_i < 0 || B_i >= n || B_j < 0 || B_j >= n)
                    continue;
                if (A[i][j] == 1 && B[B_i][B_j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
        }

public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();

        int ans = 0;

        for (int rowOffset = -n + 1; rowOffset < n; rowOffset++)
        {
            for (int colOffset = -n + 1; colOffset < n; colOffset++)
            {
                ans = max(ans, countOverlaps(img1, img2, rowOffset, colOffset));
            }
        }

        return ans;
    }
};