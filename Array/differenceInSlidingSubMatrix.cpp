#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++)
        {
            for (int j = 0; j <= n - k; j++)
            {
                unordered_set<int> st;

                for (int p = i; p < i + k; p++)
                {
                    for (int q = j; q < j + k; q++)
                    {
                        st.insert(grid[p][q]);
                    }
                }
                if (st.size() == 1)
                {
                    continue;
                }
                vector<int> v(st.begin(), st.end());
                sort(v.begin(), v.end());

                int diff = INT_MAX;

                for (int i = 0; i < v.size() - 1; i++)
                {
                    diff = min(diff, abs(v[i] - v[i + 1]));
                }
                result[i][j] = diff;
            }
        }
        return result;
    }
};