#include <bits/stdc++.h>
using namespace std;

/**
 * Solution class for finding the minimum cost to split a number down to 1.
 * 
 * The problem involves recursively splitting a number into two parts until all parts become 1.
 * Each split of a number into two parts has a cost equal to the product of those two parts.
 * 
 * @class Solution
 * @method minCost(int n)
 * @param n The number to split
 * @return The minimum total cost to split n down to individual 1s
 * 
 * @details
 * Uses dynamic programming where dp[i] represents the minimum cost to split i down to 1s.
 * 
 * For each number i:
 * - If i is odd: split into i/2 and i/2+1 parts
 *   Cost = (i/2) * (i/2+1) + dp[i/2] + dp[i/2+1]
 * - If i is even: split into two equal parts of i/2
 *   Cost = (i/2) * (i/2) + 2 * dp[i/2]
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution {
public:
    typedef long long ll;
    int minCost(int n) {
        vector<ll> dp(n+1,0);
        

        for(int i=2;i<=n;i++){
            if(i % 2 == 1){
                dp[i] = (i/2)*(i/2 +1) + dp[i/2] + dp[i/2 +1];
            }else{
                dp[i] = (i/2)*(i/2) + dp[i/2] + dp[i/2];
            }
        }
        return dp[n];
    }
};