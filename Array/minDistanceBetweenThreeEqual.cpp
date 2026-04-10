#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, deque<int>> m;

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            m[nums[i]].push_back(i);
            if (m[nums[i]].size() == 3)
            {
                deque<int> &dq = m[nums[i]];
                int a = dq.front();
                dq.pop_front();
                int b = dq.front();
                dq.pop_front();
                int c = dq.front();
                dq.pop_front();

                ans = min(ans, abs(a - b) + abs(b - c) + abs(c - a));
                dq.push_back(b);
                dq.push_back(c);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};