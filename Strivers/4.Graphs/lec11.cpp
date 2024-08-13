#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
bool bfs(vector<int> adj[], vector<int> &visited, int src)
{

    queue<pair<int, int>> q;
    // node parent
    q.push({src, -1});
    visited[src] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
            else if (parent != it)
                return true;
        }
    }
    return false;
}
bool canFinish(int n, vector<vector<int>> &arr)
{

    vector<int> visited(n, 0);
    vector<int> adj[n];
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        adj[arr[i][0]].push_back(arr[i][1]);
        // adj[arr[i][1]].push_back(arr[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (bfs(adj, visited, i) == true)
                return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> arr = { {1,0}};
    cout << canFinish(2, arr);
}