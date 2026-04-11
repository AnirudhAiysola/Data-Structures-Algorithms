#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    bool check(int k, vector<int> &charge, vector<int> &run, ll budget)
    {
        int n = charge.size();
        ll curr = 0, sum = 0;
        int i = 0, j = 0;

        deque<int> dq;

        while (j < n)
        {
            sum += run[j];
            while (!dq.empty() && charge[dq.back()] < charge[j])
            {
                dq.pop_back();
            }
            dq.push_back(j);

            if (j - i + 1 == k)
            {
                while (j - dq.front() >= k)
                    dq.pop_front();
                curr = 1LL * (charge[dq.front()] + k * (sum));
                if (curr <= budget)
                    return true;
                sum -= run[i];
                i++;
            }

            j++;
        }
        return false;
    }
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        int n = chargeTimes.size();

        int low = 1, high = n;

        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, chargeTimes, runningCosts, budget))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};