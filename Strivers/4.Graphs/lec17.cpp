#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;
// bipartite graph
// color graoh with 2 such that no 2 adjacent nodes has same colors
// using bfs

bool a(int s,int n,vector<int>adj[],vector<int>&visited)
{

    visited[s] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        int col = visited[node];
        q.pop();
        for (auto it : adj[node])
        {
            // not colored
            if (visited[it] == -1)
            {
                visited[it] = !col;
                q.push(it);
            }
            // if it is colored
            else if (visited[it] == col)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
     vector<vector<int>> arr = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    int n = arr.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (auto it : arr[i])
        {
            adj[i].push_back(it);
        }
    }

    vector<int> visited(n, -1);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==-1)
        {
            if(a(i,n,adj,visited)==false)
            cout<<0;
        }

    }
    cout<<1;
}