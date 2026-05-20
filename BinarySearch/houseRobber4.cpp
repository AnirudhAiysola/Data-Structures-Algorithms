#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int mx, vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n;)
        {
            if (nums[i] <= mx)
            {
                count++;
                i += 2;
            }
            else
            {
                i++;
            }
        }
        return count >= k;
    }

public:
    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();

        int low = 1, high = *max_element(nums.begin(), nums.end());

        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, nums, k))
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