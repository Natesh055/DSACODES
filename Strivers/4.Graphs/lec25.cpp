#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main()
{
    vector<vector<int>> arr = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    int n = arr.size();
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : arr[i])
        {
            adj[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
vector<int>visited;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        visited.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }

}