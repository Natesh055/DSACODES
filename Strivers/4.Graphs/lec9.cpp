#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void dfs(vector<vector<int>> &arr, int sr, int sc, int color, vector<vector<int>> &ans, vector<vector<int>> &visited)
{

    ans[sr][sc] = color;
    visited[sr][sc]=1;
    if (sr < arr.size() - 1 && arr[sr + 1][sc] == arr[sr][sc] && !visited[sr+1][sc])
    {
        dfs(arr, sr + 1, sc, color, ans, visited);
    }
    if (sr > 0 && arr[sr - 1][sc] == arr[sr][sc] && !visited[sr-1][sc])
    {
        dfs(arr, sr - 1, sc, color, ans, visited);
    }

    if (sc > 0 && arr[sr][sc - 1] == arr[sr][sc] && !visited[sr][sc-1])
    {
        dfs(arr, sr, sc - 1, color, ans, visited);
    }

    if (sc < arr[sr].size() - 1 && arr[sr][sc + 1] == arr[sr][sc] && !visited[sr][sc+1])
    {
        dfs(arr, sr, sc + 1, color, ans,visited);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &arr, int sr, int sc, int color)
{
    vector<vector<int>> ans=arr;
    vector<vector<int>> visited(arr.size(), vector<int>(arr[0].size(), 0));
    
    dfs(arr, sr, sc, color, ans,visited);
    for (int i = 0; i < arr.size(); i++)
    {
        for (auto it : ans[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (auto it : arr[i])
    //     {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }
    floodFill(arr, 1, 1, 2);
}