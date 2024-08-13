#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
// replace x with o's

void dfs(int x, int y, vector<vector<char>> &board, vector<vector<int>> &visited, int n, int m)
{
    visited[x][y] = 1;
    // check for top right bottom left
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = x + delrow[i];
        int ncol = y + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && board[nrow][ncol]=='O')
        {
            dfs(nrow,ncol,board,visited,n,m);
        }
    }
}
void solve(vector<vector<char>> &board)
{
}
int main()
{

    vector<vector<char>> board;

    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    // marking boundaries
    for (int i = 0; i < m; i++)
    {
        // firsst row
        if (!visited[0][i] && board[0][i] == 'O')
        {
            dfs(0, i, board, visited, n, m);
        }

        if (!visited[n - 1][i] && board[n - 1][0] == 'O')
        {
            dfs(n - 1, i, board, visited, n, m);
        }
    }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && board[i][0] == 'O')
            {
                dfs(i, 0, board, visited, n, m);
            }
            if (!visited[i][m - 1] && board[i][m - 1] == 'O')
            {
                dfs(i, m - 1, board, visited, n, m);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
