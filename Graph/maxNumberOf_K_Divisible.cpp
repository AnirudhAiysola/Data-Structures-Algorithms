#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Solves the problem of finding the maximum number of k-divisible components in a tree.
 * 
 * This solution uses a graph-based approach to partition a tree into components where
 * each component's sum of node values is divisible by k.
 */

/**
 * @brief Performs a DFS traversal to calculate component sums and count valid partitions.
 * 
 * @param node The current node being processed in the DFS.
 * @param adj Reference to the adjacency list representing the tree structure.
 * @param values Reference to the vector containing values for each node.
 * @param ans Reference to the counter for k-divisible components found.
 * @param k Reference to the divisor value for component validation.
 * @param vis Reference to the visited array to track processed nodes.
 * 
 * @return The sum of the subtree rooted at the current node. Returns 0 if the sum
 *         is divisible by k (indicating a valid component), otherwise returns the remainder.
 * 
 * @note This function modifies the ans parameter by incrementing it when a valid
 *       k-divisible component is found.
 */
long long solve(int node, vector<vector<int>> &adj, vector<int> &values, 
                int &ans, int &k, vector<int> &vis);

/**
 * @brief Finds the maximum number of components with sums divisible by k in a tree.
 * 
 * @param n The total number of nodes in the tree (numbered 0 to n-1).
 * @param edges Reference to a vector of edges, where each edge is represented as [u, v].
 * @param values Reference to a vector containing integer values for each node.
 * @param k The divisor used to validate component sums.
 * 
 * @return The maximum number of tree components that can be formed such that each
 *         component's sum of node values is divisible by k.
 * 
 * @complexity Time: O(n) - Single DFS traversal of all nodes.
 *             Space: O(n) - For adjacency list and visited array.
 */
int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k);
class Solution
{
public:
    long long solve(int node, vector<vector<int>> &adj, vector<int> &values, int &ans, int &k, vector<int> &vis)
    {
        long long sum = values[node];
        vis[node] = 1;

        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                sum += solve(it, adj, values, ans, k, vis);
            }
        }
        if (sum % k == 0)
        {
            ans++;
            sum = 0;
        }
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        vector<vector<int>> adj(n);

        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 0;
        vector<int> vis(n, 0);

        solve(0, adj, values, ans, k, vis);

        return ans;
    }
};