#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;
// bipartite graph
// color graoh with 2 such that no 2 adjacent nodes has same colors
// using dfs



bool dfs(int node,int col,vector<int>adj[],vector<int>&visited)
{
    visited[node] = col;

    for(auto it:adj[node])
    {
        if(visited[it]==-1)
        {
            if(dfs(it,!col,adj,visited)==false)
            return false;

        }
            else if(visited[node]==visited[it])
            return false;
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
    vector<int>visited(n,-1);

    for(int i=0;i<n;i++)
    {
        if(visited[i]==-1)
        {
           if( dfs(i,0,adj,visited) ==false){
            return 0;
           }
        }
    }
    return 1;
}