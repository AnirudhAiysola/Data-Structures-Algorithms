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
    int maxActivated(vector<vector<int>> &points)
    {
        int n = points.size();

        UnionFind uf(n);

        unordered_map<int, int> xMap, yMap;
        xMap[points[0][0]] = 0;
        yMap[points[0][1]] = 0;

        for (int i = 1; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            if (xMap.count(x))
            {
                uf.unionBySize(xMap[x], i);
            }
            if (yMap.count(y))
            {
                uf.unionBySize(yMap[y], i);
            }
            xMap[x] = i;
            yMap[y] = i;
        }
        int first = 0, second = 0;

        for (int i = 0; i < n; i++)
        {
            if (uf.findParent(i) == i)
            {
                if (uf.size[i] > first)
                {
                    second = first;
                    first = uf.size[i];
                }
                else if (uf.size[i] > second)
                {
                    second = uf.size[i];
                }
            }
        }
        return first + second + 1;
    }
};