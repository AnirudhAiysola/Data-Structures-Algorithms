#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int k, vector<vector<int>> &tasks)
    {
        int n = tasks.size();

        for (auto &it : tasks)
        {
            if (k - it[1] < 0)
                return false;
            k -= it[0];
        }
        return true;
    }

public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        int n = tasks.size();

        int low = 1, high = INT_MAX;

        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b)
             { return abs(a[0] - a[1]) > abs(b[0] - b[1]); });

        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, tasks))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};