#include <bits/stdc++.h>
using namespace std;


/**
 * Solution
 *
 * @brief
 *   Compute the maximum sum of products by selecting exactly k pairs (a_i, b_j)
 *   from two integer arrays nums1 and nums2. Pairs must respect the original
 *   order of each array (i.e., if (i1,j1) and (i2,j2) are chosen with i1<i2
 *   then j1<j2 must also hold). The algorithm uses recursion with 3D
 *   memoization (DP) over indices (i, j) and remaining pairs k.
 *
 * Public methods:
 *   - long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
 *       Entry point. Initializes DP table and invokes the recursive solver.
 *
 * Recursive helper:
 *   - ll solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int k,
 *              vector<vector<vector<ll>>>& dp)
 *       Returns the maximum score achievable using suffixes starting at
 *       nums1[i], nums2[j] and selecting exactly k pairs.
 *       Base cases:
 *         * if k == 0 -> return 0 (no more pairs needed)
 *         * if i >= nums1.size() || j >= nums2.size() -> impossible to pick k
 *           pairs -> returns a large negative sentinel (NEG_INF) to indicate
 *           infeasible state.
 *       Transitions (take maximum of):
 *         * pair current elements: nums1[i]*nums2[j] + solve(i+1, j+1, k-1)
 *         * skip nums1[i]: solve(i+1, j, k)
 *         * skip nums2[j]: solve(i, j+1, k)
 *       Memoization:
 *         * dp[i][j][k] stores computed results; unvisited entries use
 *           LLONG_MIN as sentinel.
 *
 * Notes and assumptions:
 *   - Uses signed 64-bit (long long) for products and sums to avoid overflow
 *     on typical constraints (products of up to 32-bit ints).
 *   - NEG_INF is a sufficiently small negative constant used for infeasible
 *     branches so they are never chosen as maxima when a valid solution exists.
 *   - The algorithm assumes k >= 0; if k > min(nums1.size(), nums2.size())
 *     the result will be infeasible (NEG_INF) per the logic above.
 *
 * Complexity:
 *   - Time: O(n * m * k) where n = nums1.size(), m = nums2.size().
 *     Each state (i, j, k) is computed at most once and each computation does
 *     O(1) work.
 *   - Space: O(n * m * k) for the DP table plus recursion stack depth up to
 *     O(n + m) in the worst case.
 *
 * Return value:
 *   - maxScore(...) returns the maximum achievable sum (long long). If no
 *     valid selection of k pairs exists, the algorithm will return the NEG_INF
 *     sentinel (a very large negative number).
 */
class Solution {
public:
    typedef long long ll;
    const ll NEG_INF = -1e15;

    ll solve(int i, int j, vector<int> &nums1, vector<int> &nums2, int k,
             vector<vector<vector<ll>>> &dp){

        if(k == 0) return 0;

        if(i >= nums1.size() || j >= nums2.size())
            return NEG_INF;

        if(dp[i][j][k] != LLONG_MIN)
            return dp[i][j][k];

        ll pair = 1LL * nums1[i] * nums2[j] + solve(i+1, j+1, nums1, nums2, k-1, dp);

        ll skip_i = solve(i+1, j, nums1, nums2, k, dp);

        ll skip_j = solve(i, j+1, nums1, nums2, k, dp);

        return dp[i][j][k] = max({pair, skip_i, skip_j});
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<vector<ll>>> dp(
            n, vector<vector<ll>>(m, vector<ll>(k+1, LLONG_MIN))
        );

        return solve(0,0,nums1,nums2,k,dp);
    }
};