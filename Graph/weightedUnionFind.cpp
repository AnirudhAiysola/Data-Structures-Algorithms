#include <bits/stdc++.h>
using namespace std;

class WeightedUnionFind
{
public:
    vector<int> parent;
    vector<int> size;
    vector<int> dist; // parity distance to parent;

    WeightedUnionFind(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        dist.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    pair<int, int> findParent(int node)
    {
        if (parent[node] == node)
            return {node, 0};
        auto [root, d] = findParent(parent[node]);
        dist[node] ^= dist[parent[node]];
        parent[node] = root;
        return {root, dist[node]};
    }
    bool unionBySize(int u, int v, int w)
    {
        auto [up, du] = findParent(u);
        auto [vp, dv] = findParent(v);

        if (up == vp)
        {
            // same component
            return (du ^ dv ^ w) == 0;
        }
        // different component
        if (size[up] <= size[vp])
        {
            parent[up] = vp;
            size[vp] += size[up];
            dist[up] = du ^ dv ^ w;
        }
        else
        {
            parent[vp] = up;
            size[up] += size[vp];
            dist[vp] = du ^ dv ^ w;
        }
        return true;
    }
};