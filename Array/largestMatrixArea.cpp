#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefixCount(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            prefixCount[m - 1][i] = matrix[m - 1][i];
            for (int j = m - 2; j >= 0; j--)
            {
                prefixCount[j][i] += matrix[j][i] == 1 ? prefixCount[j + 1][i] + 1 : 0;
            }
        }

        int ans = 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (prefixCount[j][i] > 0)
                {
                    mp[j].push_back(prefixCount[j][i]);
                }
            }
        }
        for (auto &it : mp)
        {
            sort(it.second.begin(), it.second.end());
            int s = it.second.size();
            for (int i = 0; i < it.second.size(); i++)
            {
                ans = max(ans, it.second[i] * (s - i));
            }
        }
        return ans;
    }
};