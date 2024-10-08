#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
// 01 matrix

int main()
{
    vector<vector<int>> arr = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                visited[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        ans[row][col] = steps;
        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0)
            {
                visited[nrow][ncol] = 1;
                q.push({{nrow,ncol},steps+1});
            }
        }
    }
    
}