#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        int total = 0, count = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }

                if (grid[i][j] != 0)
                {
                    total++;
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            count++;

            time = max(time, t);
            q.pop();

            visited[row][col] = 2;

            for (auto it : directions)
            {
                int nrow = row + it.first;
                int ncol = col + it.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    (grid[nrow][ncol] == 1) && (visited[nrow][ncol] != 2))
                {

                    visited[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        return total == count ? time : -1;
    }
};