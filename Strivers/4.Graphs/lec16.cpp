#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;
// number of distinct islands

void dfs(int row, int col, vector<vector<int>> arr, vector<vector<int>> &visited, vector<pair<int, int>> &vec, int row0, int col0)
{
    int m = arr.size();
    int n = arr[0].size();
    visited[row][col] = 1;
    vec.push_back({row - row0, col - col0});
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]==0 && arr[nrow][ncol]==1)
        {
            dfs(nrow,ncol,arr,visited,vec,row0,col0);
        }
    }
}
int main()
{
    vector<vector<int>> arr =
        {{1, 1, 0, 0, 0},
         {1, 1, 0, 0, 0},
         {0, 0, 0, 1, 1},
         {0, 0, 0, 1, 1}};
    int m = arr.size();
    int n = arr[0].size();
    vector<pair<int, int>> vec;
    set<vector<pair<int, int>>> st;
    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!visited[i][j] && arr[i][j]==1)
            {
                dfs(i,j,arr,visited,vec,i,j);
                st.insert(vec);
            }
        }
    }
    cout<<st.size();
}