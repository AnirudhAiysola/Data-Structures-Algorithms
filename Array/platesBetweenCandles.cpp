#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();

        vector<int> nextCandleToLeft(n, -1);
        vector<int> nextCandleToRight(n, n);

        nextCandleToRight[n - 1] = s[n - 1] == '|' ? n - 1 : n;
        for (int i = n - 2; i >= 0; i--)
        {
            nextCandleToRight[i] = (s[i] == '|' ? i : nextCandleToRight[i + 1]);
        }
        nextCandleToLeft[0] = s[0] == '|' ? 0 : -1;
        for (int i = 1; i < n; i++)
        {
            nextCandleToLeft[i] = (s[i] == '|' ? i : nextCandleToLeft[i - 1]);
        }

        vector<int> prefixCount(n, 0);
        prefixCount[0] = (s[0] == '*');

        for (int i = 1; i < n; i++)
        {
            prefixCount[i] = prefixCount[i - 1] + (s[i] == '*');
        }

        vector<int> result;

        for (auto &it : queries)
        {
            int left = it[0];
            int right = it[1];

            int r = nextCandleToLeft[right];
            int l = nextCandleToRight[left];

            if (l >= r || l == -1 || r == n)
            {
                result.push_back(0);
            }
            else
            {
                int val = prefixCount[r] - (l - 1 >= 0 ? prefixCount[l - 1] : 0);
                result.push_back(val);
            }
        }
        return result;
    }
};