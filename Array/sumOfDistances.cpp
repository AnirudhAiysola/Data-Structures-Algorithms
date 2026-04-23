#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    vector<long long> distance(vector<int> &nums)
    {
        int n = nums.size();

        vector<ll> result(n);

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++)
        {
            groups[nums[i]].push_back(i);
        }

        for (auto &it : groups)
        {
            if (it.second.size() > 0)
            {
                vector<int> &data = it.second;

                vector<ll> prefixSum(data.size(), 0), suffixSum(data.size(), 0);
                for (int i = 1; i < data.size(); i++)
                {
                    prefixSum[i] = prefixSum[i - 1] + data[i - 1];
                }
                for (int i = data.size() - 2; i >= 0; i--)
                {
                    suffixSum[i] = suffixSum[i + 1] + data[i + 1];
                }

                for (int i = 0; i < data.size(); i++)
                {
                    ll val = 0;
                    ll L = i;
                    ll R = data.size() - i - 1;
                    val += abs(data[i] * L - prefixSum[i]);
                    val += abs(data[i] * R - suffixSum[i]);
                    result[data[i]] = val;
                }
            }
        }
        return result;
    }
};