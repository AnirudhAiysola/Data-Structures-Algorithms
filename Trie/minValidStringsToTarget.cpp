#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct TrieNode
    {
        TrieNode *children[26];

        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };

    TrieNode *root = new TrieNode();

    void insertWord(string &str)
    {
        TrieNode *curr = root;

        for (char ch : str)
        {
            int idx = ch - 'a';

            if (!curr->children[idx])
            {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }
    }

    int solve(int index, string &target, vector<int> &dp)
    {
        if (index == target.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        TrieNode *curr = root;

        int ans = 1e9;

        for (int i = index; i < target.size(); i++)
        {
            int idx = target[i] - 'a';

            if (!curr->children[idx])
                break;

            curr = curr->children[idx];

            ans = min(ans, 1 + solve(i + 1, target, dp));
        }

        return dp[index] = ans;
    }

    int minValidStrings(vector<string> &words, string target)
    {

        for (auto &it : words)
        {
            insertWord(it);
        }

        vector<int> dp(target.size(), -1);

        int ans = solve(0, target, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};