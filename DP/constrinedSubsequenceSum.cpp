#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> dp = nums;

        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            // clear out invalid indices from deque
            while (!dq.empty() && i - dq.front() > k)
            {
                dq.pop_front();
            }
            int prev = dq.empty() ? 0 : max(0, dp[dq.front()]);
            dp[i] = max(dp[i], nums[i] + prev);
            // flush out bad indices
            while (!dq.empty() && dp[dq.back()] < dp[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};