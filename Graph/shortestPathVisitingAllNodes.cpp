#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();

        queue<tuple<int, int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++)
        {
            q.push({0, i, 1 << i});
            vis[i][1 << i] = true;
        }

        while (!q.empty())
        {
            auto [cost, node, mask] = q.front();
            q.pop();

            if (mask == (1 << n) - 1)
                return cost;

            for (int nxt : graph[node])
            {
                int newMask = mask | (1 << nxt);

                if (!vis[nxt][newMask])
                {
                    vis[nxt][newMask] = true;
                    q.push({cost + 1, nxt, newMask});
                }
            }
        }

        return -1;
    }
};