#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
// surrounded enclaves
// using dfs memory limit exceeded

// void dfs(int row,int col,vector<vector<int>>arr,vector<vector<int>>visited,int m,int n)
// {
//     visited[row][col]=1;
//     vector<int>delrow = {-1,0,1,0};
//     vector<int>delcol = {0,1,0,-1};

//     for(int i=0;i<4;i++)
//     {
//         int nrow = row+delrow[i];
//         int ncol = col +delcol[i];
//         if(nrow>=0 && nrow<m  && ncol>=0 &&ncol<n &&!visited[nrow][ncol] &&arr[nrow][ncol]==1)
//         dfs(nrow,ncol,arr,visited,m,n);
//     }

// }
// int main()
// {
//     vector<vector<int>>arr = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
//     int m = arr.size();
//     int n = arr[0].size();
//     vector<vector<int>>visited(m,vector<int>(n,0));

//     // traversing the row
//     for(int i=0;i<n;i++)
//     {
//         // first row
//         if(arr[0][i]==1 &&!visited[0][i])
//         {
//             dfs(0,i,arr,visited,m,n);
//         }
//         if(arr[m-1][i]==1 &&!visited[m-1][i])
//         dfs(m-1,i,arr,visited,m,n);
//     }

//     for(int i=0;i<m;i++)
//     {
//         // first col
//         if(arr[i][0]==1 &&!visited[i][0])
//         {
//             dfs(i,0,arr,visited,m,n);
//         }
//         if(arr[i][n-1]==1 &&!visited[i][n-1])
//         dfs(i,n-1,arr,visited,m,n);
//     }

//     int count =0;
//     for(int i=0;i<m;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(arr[i][j]==1 && !visited[i][j]==1)
//             count++;
//         }
//     }
// }



// O(N*M*4)
int main()
{
    vector<vector<int>> arr = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    // traversing the row

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        // first row
        if (arr[0][i] == 1 && !visited[0][i])
        {
            q.push({0, i});
            visited[0][i] = 1;
        }
        if (arr[m - 1][i] == 1 && !visited[m - 1][i])
        {
            q.push({m - 1, i});
            visited[m - 1][i] = 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        // first col
        if (arr[i][0] == 1 && !visited[i][0])
        {
            q.push({i, 0});
            visited[i][0] = 1;
        }
        if (arr[i][n - 1] == 1 && !visited[i][n - 1])
        {
            q.push({i, n - 1});
            visited[i][n - 1] = 1;
        }
    }

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && arr[nrow][ncol] == 1)
            {
                visited[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
    int count=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]==1 &&  !visited[i][j])
            count++;
        }
    }
    return count;
}