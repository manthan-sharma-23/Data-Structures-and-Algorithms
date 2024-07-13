#include <bits/stdc++.h>

using namespace std;

bool isMovable(int row, int col, const vector<vector<int>> &maze)
{
    int n = maze.size();
    return (row >= 0 && col >= 0 && row < n && col < n) && maze[row][col] == 1;
}

void find(int row, int col, vector<vector<int>> maze, string &path, int n, vector<string> &paths)
{
    if (row == n - 1 && col == n - 1)
    {
        paths.push_back(path);
        return;
    }

    char lastMove = path.empty() ? '.' : path[path.size() - 1];

    if (isMovable(row, col - 1, maze) && lastMove != 'D')
    {
        path.push_back('T');
        find(row, col - 1, maze, path, n, paths);
        path.pop_back();
    }
    if (isMovable(row - 1, col, maze) && lastMove != 'R')
    {
        path.push_back('L');
        find(row - 1, col, maze, path, n, paths);
        path.pop_back();
    }
    if (isMovable(row, col + 1, maze) && lastMove != 'L')
    {
        path.push_back('R');
        find(row, col + 1, maze, path, n, paths);
        path.pop_back();
    }
    if (isMovable(row + 1, col, maze) && lastMove != 'T')
    {
        path.push_back('D');
        find(row + 1, col, maze, path, n, paths);
        path.pop_back();
    }
}

vector<string> findPath(vector<vector<int>> m, int n)
{
    vector<string> v;
    string s;
    s.reserve(30);

    find(0, 0, m, s, n, v);
    return v;
}

int main()
{
    vector<vector<int>> v = {{1, 1}, {1, 1}};

    findPath(v, v.size());
    return 0;
}