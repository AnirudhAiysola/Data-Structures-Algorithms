#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStrings(string s1, string s2)
    {
        int n = s1.size();

        unordered_map<char, int> odd, even;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                even[s1[i]]++;
            }
            else
            {
                odd[s1[i]]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (!even.count(s2[i]))
                    return false;
                even[s2[i]]--;
                if (even[s2[i]] == 0)
                    even.erase(s2[i]);
            }
            else
            {
                if (!odd.count(s2[i]))
                    return false;
                odd[s2[i]]--;
                if (odd[s2[i]] == 0)
                    odd.erase(s2[i]);
            }
        }
        return true;
    }
};