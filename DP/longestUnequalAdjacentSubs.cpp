#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPick(string &s, string &t)
    {
        if (s.size() != t.size())
            return false;
        int n = s.size(), count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
                count++;
        }
        return count == 1;
    }
    void dfs(int node, vector<string> &result, vector<string> &words, vector<pair<int, int>> &dp)
    {
        if (node == -1)
            return;
        result.push_back(words[node]);
        dfs(dp[node].first, result, words, dp);
        return;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();

        vector<pair<int, int>> dp(n, {-1, 1});

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (canPick(words[j], words[i]) && groups[i] != groups[j])
                {
                    if (dp[i].second < 1 + dp[j].second)
                    {
                        dp[i].second = 1 + dp[j].second;
                        dp[i].first = j;
                    }
                }
            }
        }
        int idx = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            if (count < dp[i].second)
            {
                idx = i;
                count = dp[i].second;
            }
        }
        vector<string> result;
        dfs(idx, result, words, dp);

        reverse(result.begin(), result.end());

        return result;
    }
};