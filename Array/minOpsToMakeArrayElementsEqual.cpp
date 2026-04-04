#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    int getIndex(int x, vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x)
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
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        int q = queries.size();

        // sort the nums
        sort(nums.begin(), nums.end());
        vector<ll> prefix(n, 0), suffix(n, 0);

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + 1LL * nums[i - 1];
        }
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + 1LL * nums[i];
        }

        ll total = accumulate(nums.begin(), nums.end(), 0LL);

        vector<ll> result;

        for (auto &it : queries)
        {
            int idx = getIndex(it, nums);
            if (idx == n)
            {
                ll val = 1LL * it * n - total;
                result.push_back(val);
            }
            else
            {
                ll L = prefix[idx];
                ll R = suffix[idx];
                ll val = 1LL * idx * it - L + R - 1LL * (n - idx) * it;
                result.push_back(val);
            }
        }
        return result;
    }
};