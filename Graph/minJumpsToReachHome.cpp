#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {

        unordered_set<int> st(forbidden.begin(), forbidden.end());

        vector<vector<int>> vis(6000, vector<int>(2, 0));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        /*
        {cost,pos,dir}
        initially cost is 0, poition is 0, first direction is forwrd 0
        */
        vis[0][0] = 1;

        while (!q.empty())
        {
            auto [cost, pos, dir] = q.front();
            q.pop();

            if (pos == x)
                return cost;
            /*
            Jump forward or backward if previous was not backward
            */

            // backward
            if (dir == 0 && pos - b >= 0 && !st.count(pos - b) && !vis[pos - b][1])
            {
                q.push({cost + 1, pos - b, 1});
                vis[pos - b][1] = 1;
            }
            // forward
            if (pos + a < 5999 && !st.count(pos + a) && !vis[pos + a][0])
            {
                q.push({cost + 1, pos + a, 0});
                vis[pos + a][0] = 1;
            }
        }
        return -1;
    }
};