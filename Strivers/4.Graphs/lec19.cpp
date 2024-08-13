#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

// detect a cycle using dfs
bool dfs(int node ,vector<int>adj[],vector<int>&visited,int n)
{
    visited[node] = 1;
    for(auto it:adj[node])
    {
        if(visited[it] == 0)//neighbour not visited
        {
            if(dfs(it,adj,visited,n))
            return true;
        }

        else if(visited[it]==1)
        return true;
    }
    visited[node]=2;
    return false;
}
int main()
{
    vector<vector<int>>arr = {{0,1},{1,2},{2,3},{3,3}};
    int n = 4;
    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        adj[arr[i][0]].push_back(arr[i][1]);
    }
    vector<int>visited(n,0);

    for(int i=0;i<n;i++)
    {
       if(!dfs(i,adj,visited,n)){
        cout<<0;
       return 0;}
    }
    cout<<1;
    return 1;
}