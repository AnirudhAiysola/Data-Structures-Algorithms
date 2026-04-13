#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();

        vector<pair<int, int>> data;
        long long original = 0;
        for (int i = 0; i < n; i++)
        {
            data.push_back({nums1[i], nums2[i]});
            original = (original + abs(nums1[i] - nums2[i]));
        }
        // sort
        sort(data.begin(), data.end(), [&](pair<int, int> &a, pair<int, int> &b)
             { return abs(a.first - a.second) > abs(b.first - b.second); });
        sort(nums1.begin(), nums1.end());

        long long ans = original;
        for (int i = 0; i < n; i++)
        {
            long long curr = original - abs(data[i].first - data[i].second);
            auto it = lower_bound(nums1.begin(), nums1.end(), data[i].second);

            int next = (it == nums1.end()) ? 1e9 : *it;
            int prevV = (it != nums1.begin()) ? *prev(it) : 1e9;

            ans = min(ans, curr + min(abs(next - data[i].second), abs(prevV - data[i].second)));
        }
        return ans % MOD;
    }
};