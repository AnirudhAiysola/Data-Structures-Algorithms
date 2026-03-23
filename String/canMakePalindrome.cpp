#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<vector<int>> prefix(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';
            if (i == 0)
            {
                prefix[i][idx]++;
            }
            else
            {
                prefix[i] = prefix[i - 1];
                prefix[i][idx]++;
            }
        }
        vector<bool> result;

        for (auto &it : queries)
        {
            int l = it[0];
            int r = it[1];
            int k = it[2];

            // adjust frequencies
            vector<int> right = prefix[r];
            vector<int> left(26, 0);
            if (l - 1 >= 0)
                left = prefix[l - 1];

            for (int i = 0; i < 26; i++)
            {
                right[i] -= left[i];
            }
            int even = 0, odd = 0;

            for (int i = 0; i < 26; i++)
            {
                if (right[i] > 0 && right[i] % 2 == 0)
                {
                    even++;
                }
                else if (right[i] > 0 && right[i] % 2)
                {
                    odd++;
                }
            }
            if (odd - 2 * k <= 1)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
        return result;
    }
};