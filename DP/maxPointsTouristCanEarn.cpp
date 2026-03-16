#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int city, int day, int k, vector<vector<int>> &stay, vector<vector<int>> &travel, vector<vector<int>> &dp)
    {
        if (day == k)
            return 0;

        if (dp[city][day] != -1)
            return dp[city][day];
        /*
        On a current day I can stay in the same city or got to another city
        */
        int same = stay[day][city] + solve(city, day + 1, k, stay, travel, dp);
        // move to different city
        int move = 0;
        for (int i = 0; i < stay[0].size(); i++)
        {
            if (city != i)
            {
                move = max(move, travel[city][i] + solve(i, day + 1, k, stay, travel, dp));
            }
        }
        return dp[city][day] = max(move, same);
    }

public:
    int maxScore(int n, int k, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore)
    {
        int ans = 0;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, solve(i, 0, k, stayScore, travelScore, dp));
        }

        return ans;
    }
};