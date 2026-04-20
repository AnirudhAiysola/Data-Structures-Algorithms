#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();

        unordered_map<int, int> filled;
        set<int> st;

        vector<int> result(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (rains[i] > 0 && !filled.count(rains[i]))
            {
                filled[rains[i]] = i;
            }
            else if (rains[i] == 0)
            {
                st.insert(i);
                result[i] = 0;
            }
            else if (rains[i] > 0 && filled.count(rains[i]))
            {
                if (st.empty())
                    return {};
                auto it = st.lower_bound(filled[rains[i]]);
                if (it == st.end())
                    return {};
                result[*it] = rains[i];
                st.erase(it);
                filled[rains[i]] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (result[i] == 0)
                result[i] = 1;
        }
        return result;
    }
};