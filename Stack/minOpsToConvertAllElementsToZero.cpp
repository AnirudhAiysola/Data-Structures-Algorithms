#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> NSR(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
                result[i] = st.top();
            st.push(i);
        }
        return result;
    }

public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> nsr = NSR(nums);
        unordered_map<int, int> m;

        int ops = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                continue;
            if (m.count(nums[i]) && m[nums[i]] > i)
                continue;
            int next = nsr[i];
            ops++;
            m[nums[i]] = next;
        }
        return ops;
    }
};