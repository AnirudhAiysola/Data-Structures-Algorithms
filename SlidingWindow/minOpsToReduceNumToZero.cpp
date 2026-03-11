#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();

        ll total = accumulate(nums.begin(), nums.end(), 0);
        ll k = total - x;
        if (k < 0)
            return -1;

        ll i = 0, j = 0, ans = INT_MIN, sum = 0;

        while (j < n)
        {
            sum += nums[j];
            while (sum > k)
            {
                sum -= nums[i];
                i++;
            }
            if (sum == k)
            {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans == INT_MIN ? -1 : n - ans;
    }
};