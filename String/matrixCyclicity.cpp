#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rotateLeft(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());

        return nums;
    }
    vector<int> rotateRight(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        return nums;
    }

public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> temp = mat;

        for (int i = 0; i < m; i++)
        {
            if (i % 2 == 0)
            {
                mat[i] = rotateLeft(mat[i], k);
            }
            else
            {
                mat[i] = rotateRight(mat[i], k);
            }
        }
        return temp == mat;
    }
};