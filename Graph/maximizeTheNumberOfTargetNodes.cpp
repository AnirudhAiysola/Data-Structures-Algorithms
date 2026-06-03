#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(int source, vector<vector<int>> &adj, int k)
    {
        if (k < 0)
            return 0;
        int n = adj.size();
        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        vis[source] = 1;
        int ans = 0;

        q.push({source, 0});

        while (!q.empty())
        {
            auto [node, dist] = q.front();
            q.pop();

            for (auto &it : adj[node])
            {
                if (!vis[it] && dist + 1 <= k)
                {
                    q.push({it, dist + 1});
                    vis[it] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                               vector<vector<int>> &edges2, int k)
    {
        int m = edges1.size() + 1;
        int n = edges2.size() + 1;

        vector<int> result;

        vector<vector<int>> adj1(m), adj2(n);

        for (auto &it : edges1)
        {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for (auto &it : edges2)
        {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        int t = k - 1;

        vector<int> dist(n, 0);

        for (int j = 0; j < n; j++)
        {
            int c = bfs(j, adj2, t);
            dist[j] = c;
        }

        for (int i = 0; i < m; i++)
        {
            int other = 0;
            if (k > 0)
            {
                for (int j = 0; j < n; j++)
                {
                    other = max(other, 1 + dist[j]);
                }
            }
            int same = bfs(i, adj1, k) + 1;
            result.push_back(same + other);
        }
        return result;
    }
};