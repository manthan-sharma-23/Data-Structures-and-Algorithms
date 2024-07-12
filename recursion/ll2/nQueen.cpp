#include <bits/stdc++.h>

using namespace std;

bool isPlacable(int row, int col, const vector<string> board, int n)
{
    int row_1 = row;
    int col_1 = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;

        row--;
        col--;
    }

    row = row_1;
    col = col_1;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }

        col--;
    }

    row = row_1;
    col = col_1;

    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;

        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isPlacable(i, col, board, n))
        {
            board[i][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[i][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solve(0, board, ans, n);
    return ans;
}

int main() {}