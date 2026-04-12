#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[301][27][27]; // index, f1, f2

    int getDist(int a, int b)
    {
        if (a == -1)
            return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int index, string &word, int f1, int f2)
    {
        if (index == word.size())
            return 0;

        if (dp[index][f1 + 1][f2 + 1] != -1)
            return dp[index][f1 + 1][f2 + 1];

        int curr = word[index] - 'A';

        // use finger 1
        int useF1 = getDist(f1, curr) + solve(index + 1, word, curr, f2);

        // use finger 2
        int useF2 = getDist(f2, curr) + solve(index + 1, word, f1, curr);

        return dp[index][f1 + 1][f2 + 1] = min(useF1, useF2);
    }

    int minimumDistance(string word)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, word, -1, -1);
    }
};