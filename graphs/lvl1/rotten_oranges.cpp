#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> convertToAdjList(const vector<vector<int>> &matrix, int V)
    {

        vector<vector<int>> adj(V);
        for (int i = 1; i < V; i++)
        {
            for (int j = 1; j < V; j++)
            {
                if (matrix[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        return adj;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<vector<int>> v = convertToAdjList(grid, grid.size());
    }
};