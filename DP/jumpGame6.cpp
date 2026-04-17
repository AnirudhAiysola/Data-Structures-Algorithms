#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        dp[n - 1] = nums[n - 1];

        deque<int> dq;
        dq.push_back(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (!dq.empty() && i + k < dq.front())
            {
                dq.pop_front();
            }
            dp[i] = nums[i] + (!dq.empty() ? dp[dq.front()] : 0);
            while (!dq.empty() && dp[dq.back()] < dp[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[0];
    }
};