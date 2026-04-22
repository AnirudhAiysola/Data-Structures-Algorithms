#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles,
                                vector<vector<int>> &points)
    {
        int n = rectangles.size();

        unordered_map<int, vector<int>> groups;

        int maxHeight = 0;
        for (auto &it : rectangles)
        {
            int w = it[0];
            int h = it[1];
            maxHeight = max(maxHeight, h);
            groups[h].push_back(w);
        }
        for (auto &it : groups)
        {
            sort(it.second.begin(), it.second.end());
        }

        vector<int> result;

        for (auto &it : points)
        {
            int w = it[0];
            int h = it[1];
            int count = 0;
            for (int i = h; i <= maxHeight; i++)
            {
                vector<int> &data = groups[i];
                int idx = lower_bound(data.begin(), data.end(), w) - data.begin();
                count += data.size() - idx;
            }
            result.push_back(count);
        }
        return result;
    }
};