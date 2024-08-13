#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

// 207. Course Schedule

int main()
{
    vector<vector<int>> arr = {{1, 0}, {2, 1}, {3, 2}};
    int n = arr.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[arr[i][0]].push_back(arr[i][1]);
    }

    vector<int> indegree(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> visited;
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (indegree.size() == n)
        cout << 1;
    cout << 0;
}
