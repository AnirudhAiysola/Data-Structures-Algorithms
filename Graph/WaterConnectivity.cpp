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
        {
            parent[i] = i;
        }
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
    int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
    {

        for (int i = 1; i <= n; i++)
        {
            pipes.push_back({0, i, wells[i - 1]});
        }

        sort(pipes.begin(), pipes.end(), [&](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });

        UnionFind uf(n + 1);

        int totalCost = 0;

        for (auto &it : pipes)
        {
            int u = it[0];
            int v = it[1];

            if (uf.findParent(u) != uf.findParent(v))
            {
                uf.unionBySize(u, v);
                totalCost += it[2];
            }
        }
        return totalCost;
    }
};