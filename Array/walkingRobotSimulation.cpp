#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void changeDirection(int &dir, int next)
    {
        if (dir == 0)
        {
            dir = next == -1 ? 1 : 3;
        }
        else if (dir == 1)
        {
            dir = next == -1 ? 2 : 0;
        }
        else if (dir == 2)
        {
            dir = next == -1 ? 3 : 1;
        }
        else
        {
            dir = next == -1 ? 0 : 2;
        }
    }
    void moveNorth(vector<int> &point, int k, set<vector<int>> &st, int &ans)
    {
        vector<int> temp = point;
        while (k--)
        {
            temp[1]++;
            if (st.count(temp))
            {
                temp[1]--;
                break;
            }
            else
            {
                ans = max(ans, temp[0] * temp[0] + temp[1] * temp[1]);
            }
        }
        point = temp;
        return;
    }
    void moveEast(vector<int> &point, int k, set<vector<int>> &st, int &ans)
    {
        vector<int> temp = point;
        while (k--)
        {
            temp[0]++;
            if (st.count(temp))
            {
                temp[0]--;
                break;
            }
            else
            {
                ans = max(ans, temp[0] * temp[0] + temp[1] * temp[1]);
            }
        }
        point = temp;
        return;
    }
    void moveSouth(vector<int> &point, int k, set<vector<int>> &st, int &ans)
    {
        vector<int> temp = point;
        while (k--)
        {
            temp[1]--;
            if (st.count(temp))
            {
                temp[1]++;
                break;
            }
            else
            {
                ans = max(ans, temp[0] * temp[0] + temp[1] * temp[1]);
            }
        }
        point = temp;
        return;
    }
    void moveWest(vector<int> &point, int k, set<vector<int>> &st, int &ans)
    {
        vector<int> temp = point;
        while (k--)
        {
            temp[0]--;
            if (st.count(temp))
            {
                temp[0]++;
                break;
            }
            else
            {
                ans = max(ans, temp[0] * temp[0] + temp[1] * temp[1]);
            }
        }
        point = temp;
        return;
    }

public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {

        int m = commands.size();
        int n = obstacles.size();

        set<vector<int>> st(obstacles.begin(), obstacles.end());

        int ans = 0, dir = 0;
        vector<int> point = {0, 0};

        for (int i = 0; i < m; i++)
        {
            if (commands[i] < 0)
            {
                changeDirection(dir, commands[i]);
                continue;
            }
            if (dir == 0)
            {
                moveNorth(point, commands[i], st, ans);
            }
            else if (dir == 1)
            {
                moveEast(point, commands[i], st, ans);
            }
            else if (dir == 2)
            {
                moveSouth(point, commands[i], st, ans);
            }
            else
            {
                moveWest(point, commands[i], st, ans);
            }
        }
        return ans;
    }
};