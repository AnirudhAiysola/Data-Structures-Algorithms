#include <bits/stdc++.h>
using namespace std;

/**
 * Solution class for counting complete connected components in an undirected graph.
 * 
 * A complete component is a connected subgraph where every node is connected to 
 * every other node in that component (forming a clique).
 * 
 * @class Solution
 * 
 * @public:
 *   @method countCompleteComponents(int n, vector<vector<int>>& edges)
 *     Counts the number of complete connected components in a graph.
 *     
 *     @param n The number of nodes in the graph (nodes are 0-indexed)
 *     @param edges A vector of pairs representing undirected edges [u, v]
 *     @return The count of complete connected components
 *     
 *     Time Complexity: O(n + e) where n is nodes and e is edges
 *     Space Complexity: O(n) for adjacency list and visited arrays
 * 
 * @private:
 *   @method dfs(int node, vector<int>& vis, vector<vector<int>>& adj, int& count)
 *     Performs depth-first search to find all nodes in a connected component.
 *     
 *     @param node The current node being visited
 *     @param vis Vector tracking visited nodes
 *     @param adj Adjacency list representation of the graph
 *     @param count Reference to count of nodes in the component (incremented during traversal)
 * 
 *   @method completeCheck(int node, vector<int>& checkVis, vector<vector<int>>& adj, int& count)
 *     Verifies if a connected component is complete (every node connected to all others).
 *     Checks if each node's degree equals (count - 1).
 *     
 *     @param node The current node being checked
 *     @param checkVis Vector tracking visited nodes during validation
 *     @param adj Adjacency list representation of the graph
 *     @param count The total number of nodes in the component
 *     @return true if the component is complete, false otherwise
 */
class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, int &count)
    {
        vis[node] = 1;
        count++;

        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, count);
            }
        }
        return;
    }
    bool completeCheck(int node, vector<int> &checkVis, vector<vector<int>> &adj, int &count)
    {
        checkVis[node] = 1;
        if (adj[node].size() != count - 1)
            return false;

        for (auto &it : adj[node])
        {
            if (!checkVis[it])
            {
                if (!completeCheck(it, checkVis, adj, count))
                    return false;
            }
        }
        return true;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        int ans = 0;

        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        vector<int> checkVis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (adj[i].empty())
            {
                vis[i] = 1;
                checkVis[i] = 1;
                ans++;
            }
            if (!vis[i])
            {
                // find number of nodes in the component
                // For each node, the degree must be number of node -1
                int count = 0;
                dfs(i, vis, adj, count);
                if (completeCheck(i, checkVis, adj, count))
                    ans++;
            }
        }
        return ans;
    }
};