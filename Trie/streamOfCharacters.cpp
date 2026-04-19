#include <bits/stdc++.h>
using namespace std;

class StreamChecker
{
public:
    struct TrieNode
    {
        bool end = false;
        TrieNode *children[26] = {NULL};
    };
    TrieNode *root = new TrieNode();
    void insertWord(string &str)
    {
        int n = str.size();
        TrieNode *curr = root;

        for (int i = n - 1; i >= 0; i--)
        {
            int idx = str[i] - 'a';
            if (curr->children[idx] == NULL)
            {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->end = true;
        return;
    }
    bool isSuffix(string &str)
    {
        int n = str.size();
        TrieNode *curr = root;

        for (int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
            if (curr->end)
                return true;
        }
        return false;
    }
    string s = "";
    StreamChecker(vector<string> &words)
    {
        for (auto &it : words)
        {
            insertWord(it);
        }
    }

    bool query(char letter)
    {
        s.push_back(letter);
        TrieNode *curr = root;
        int n = s.size();

        int i = n - 1;

        while (i >= max(0, n - 200) && curr)
        {
            int idx = s[i] - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
            if (curr->end)
                return true;
            i--;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */