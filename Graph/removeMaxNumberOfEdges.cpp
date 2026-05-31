#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;
    UnionFind(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int node)
    {
        if (parent[node] == node)
            return parent[node];
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int up = findParent(u);
        int vp = findParent(v);
        if (up == vp)
            return;

        if (size[up] <= size[vp])
        {
            parent[up] = vp;
            size[vp] += size[up];
        }
        else
        {
            parent[vp] = up;
            size[up] += size[vp];
        }
        return;
    }
};
class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        UnionFind alice(n + 1), bob(n + 1);

        sort(edges.rbegin(), edges.rend());

        int ans = 0;

        for (auto &it : edges)
        {
            int t = it[0];
            int u = it[1];
            int v = it[2];

            if (t == 3)
            {
                if (alice.findParent(u) != alice.findParent(v))
                {
                    alice.unionBySize(u, v);
                    bob.unionBySize(u, v);
                }
                else
                {
                    ans++;
                }
            }
            else if (t == 1)
            {
                if (alice.findParent(u) != alice.findParent(v))
                {
                    alice.unionBySize(u, v);
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                if (bob.findParent(u) != bob.findParent(v))
                {
                    bob.unionBySize(u, v);
                }
                else
                {
                    ans++;
                }
            }
        }
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (alice.findParent(i) == i)
                count++;
            if (bob.findParent(i) == i)
                count++;
        }

        return count == 2 ? ans : -1;
    }
};