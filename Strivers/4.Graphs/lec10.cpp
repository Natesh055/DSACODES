#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int bfs(vector<vector<int>> &arr)
{
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(arr.size(), vector<int>(arr[0].size(), 0));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
            else
            visited[i][j]=0;
        }
    }
    int time = 0;
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    while (!q.empty())
    {

        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
    time = max(time,t);

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow >=0 && nrow < arr.size() && ncol >=0 && ncol < arr[0].size() && visited[nrow][ncol]!=2 && arr[nrow][ncol ] ==1) 
            {
                q.push({{nrow,ncol},t+1});
                visited[nrow][ncol] = 1;
            }
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(visited[i][j]!=2 && arr[i][j] ==1) 
            return -1;
        }
    }
    return time;
}
int orangesRotting(vector<vector<int>> &arr)
{
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return bfs(arr);
}
int main()
{
    vector<vector<int>> arr = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(arr);
}