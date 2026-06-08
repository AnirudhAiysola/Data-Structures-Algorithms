#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void fillPrefix(vector<vector<int>> &prefix, vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = matrix[i][j];
                if (i - 1 >= 0)
                    sum += prefix[i - 1][j];
                if (j - 1 >= 0)
                    sum += prefix[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0)
                    sum -= prefix[i - 1][j - 1];
                prefix[i][j] = sum;
            }
        }
    }
    int query(int r1, int c1, int r2, int c2, vector<vector<int>> &prefix)
    {
        int sum = prefix[r2][c2];
        if (r1 > 0)
            sum -= prefix[r1 - 1][c2];
        if (c1 > 0)
            sum -= prefix[r2][c1 - 1];
        if (r1 > 0 && c1 > 0)
            sum += prefix[r1 - 1][c1 - 1];
        return sum;
    }

public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> prefix(m, vector<int>(n, 0));
        fillPrefix(prefix, matrix);

        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                unordered_map<int, int> mp;
                mp[0] = 1;

                int r1 = i, r2 = j, sum = 0;

                for (int k = 0; k < n; k++)
                {
                    sum += query(r1, k, r2, k, prefix);

                    if (mp.count(sum - target))
                    {
                        ans += mp[sum - target];
                    }
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};