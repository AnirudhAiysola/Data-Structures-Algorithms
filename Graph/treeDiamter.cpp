#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Finds the diameter of a tree using two DFS passes.
 * 
 * The tree diameter is the longest path between any two nodes in the tree.
 * This solution uses a two-pass DFS approach:
 * 1. First DFS from node 0 finds one end of the diameter
 * 2. Second DFS from that end node finds the actual diameter length
 */

/**
 * @brief Performs depth-first search to find the farthest node from a starting point.
 * 
 * @param node The current node being visited
 * @param adj Reference to the adjacency list representation of the tree
 * @param vis Reference to the visited array to track visited nodes
 * @param ans Reference to the maximum distance found so far
 * @param count The current distance/depth from the starting node
 * @param finalNode Reference to store the farthest node found during traversal
 */
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &ans, int count, int &finalNode);

/**
 * @brief Calculates the diameter of a tree given its edges.
 * 
 * @param edges A vector of pairs representing edges between nodes [u, v]
 * @return The diameter of the tree (longest path length between any two nodes)
 * @note Time Complexity: O(n) where n is the number of nodes
 * @note Space Complexity: O(n) for adjacency list and visited array
 */
int treeDiameter(vector<vector<int>> &edges);
class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &ans, int count, int &finalNode)
    {
        vis[node] = 1;
        count++;

        bool flag = true;
        for (auto &it : adj[node])
        {

            if (!vis[it])
            {
                flag = false;
                dfs(it, adj, vis, ans, count, finalNode);
            }
        }
        if (flag && count > ans)
        {
            ans = max(ans, count);
            finalNode = node;
        }
        return;
    }

public:
    int treeDiameter(vector<vector<int>> &edges)
    {

        int n = edges.size();
        if (n == 0)
            return 0;

        vector<vector<int>> adj(n + 1);

        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n + 1, 0);
        int d1 = 0, f1 = -1;
        dfs(0, adj, vis, d1, 0, f1);
        fill(vis.begin(), vis.end(), 0);
        int d2 = 0, f2 = -1;
        dfs(f1, adj, vis, d2, 0, f2);

        return max(d1, d2) - 1;
    }
};