#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        int q = queries.size();

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++)
        {
            m[nums[i]].push_back(i);
        }

        vector<int> result;

        for (int i = 0; i < q; i++)
        {
            int num = nums[queries[i]];
            if (m[num].size() == 1)
            {
                result.push_back(-1);
            }
            else
            {
                int d1 = INT_MAX, d2 = INT_MAX;

                auto it1 = upper_bound(m[num].begin(), m[num].end(), queries[i]);
                if (it1 != m[num].end())
                {
                    d1 = abs(queries[i] - *it1);
                }
                else
                {
                    d1 = n - (queries[i] - m[num][0]);
                }
                auto it2 = lower_bound(m[num].begin(), m[num].end(), queries[i]);
                if (it2 != m[num].begin())
                {
                    d2 = abs(queries[i] - *prev(it2));
                }
                else
                {
                    d2 = n - (m[num].back() - queries[i]);
                }
                result.push_back(min(d1, d2));
            }
        }
        return result;
    }
};