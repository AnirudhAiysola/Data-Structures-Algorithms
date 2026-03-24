#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        typedef tuple<int, int, int, int> t; // {time,row,col,cost}
        priority_queue<t, vector<t>, greater<>> pq;
        pq.push({0, 0, 0, 1});

        vector<int> rowCoordinates = {0, -1, 0, 1};
        vector<int> colCoordinates = {1, 0, -1, 0};

        while (!pq.empty())
        {
            auto [time, row, col, cost] = pq.top();
            pq.pop();

            if (row == m - 1 && col == n - 1)
                return time;
            if (dist[row][col] < time)
                continue;

            for (int i = 0; i < 4; i++)
            {
                int nr = row + rowCoordinates[i];
                int nc = col + colCoordinates[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                int wait = 0;
                if (time < grid[nr][nc])
                {
                    wait = grid[nr][nc] - time;
                }
                wait += cost;
                int temp = cost == 2 ? 1 : 2;
                if (dist[nr][nc] > time + wait)
                {
                    dist[nr][nc] = time + wait;
                    pq.push({dist[nr][nc], nr, nc, temp});
                }
            }
        }
        return 1;
    }
};