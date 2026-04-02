#include <bits/stdc++.h>
using namespace std;

class RollingHash
{
public:
    typedef long long ll;

    const ll mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    const ll base = 31;

    vector<ll> hash1, hash2, power1, power2;

    RollingHash(vector<int> &arr)
    {
        int n = arr.size();

        hash1.resize(n + 1, 0);
        hash2.resize(n + 1, 0);
        power1.resize(n + 1, 1);
        power2.resize(n + 1, 1);

        for (int i = 0; i < n; i++)
        {
            ll val = arr[i] + 101;

            hash1[i + 1] = (hash1[i] * base + val) % mod1;
            hash2[i + 1] = (hash2[i] * base + val) % mod2;

            power1[i + 1] = (power1[i] * base) % mod1;
            power2[i + 1] = (power2[i] * base) % mod2;
        }
    }

    pair<ll, ll> getHash(int l, int r)
    {
        ll h1 = (hash1[r + 1] - (hash1[l] * power1[r - l + 1]) % mod1 + mod1) % mod1;
        ll h2 = (hash2[r + 1] - (hash2[l] * power2[r - l + 1]) % mod2 + mod2) % mod2;
        return {h1, h2};
    }
};