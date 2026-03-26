#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalMask(int mask, string &s)
    {
        int l = 0, r = s.size() - 1;

        while (l < r)
        {
            // move l to next picked index
            while (l < r && !(mask & (1 << l)))
                l++;

            // move r to previous picked index
            while (l < r && !(mask & (1 << r)))
                r--;

            if (l < r && s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
    int getProduct(int mask1, int mask2)
    {
        int count1 = 0, count2 = 0;

        for (int i = 0; i < 30; i++)
        {
            count1 += (mask1 & (1 << i)) ? 1 : 0;
            count2 += (mask2 & (1 << i)) ? 1 : 0;
        }
        return count1 * count2;
    }

public:
    void solve(int index, int &m1, int &m2, string &s, int &ans)
    {
        if (index >= s.size())
        {
            if ((m1 & m2) == 0)
            {
                if (isPalMask(m1, s) && isPalMask(m2, s))
                {
                    ans = max(ans, getProduct(m1, m2));
                }
            }
            return;
        }
        solve(index + 1, m1, m2, s, ans);
        // pick for m1
        m1 = m1 | (1 << (index)); // set
        solve(index + 1, m1, m2, s, ans);
        m1 = m1 & ~(1 << (index)); // unset
        m2 = m2 | (1 << index);    // set
        solve(index + 1, m1, m2, s, ans);
        m2 = m2 & ~(1 << (index)); // unset

        return;
    }

public:
    int maxProduct(string s)
    {
        int n = s.size();

        int mask1 = 0, mask2 = 0, ans = 0;

        solve(0, mask1, mask2, s, ans);

        return ans;
    }
};