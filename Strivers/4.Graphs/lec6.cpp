#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS
// directed graphs

void dfs(vector<int>adj[],vector<int>&ans,int node,vector<int>&visited)
{
    visited[node]=1;
    ans.push_back(node);
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            dfs(adj,ans,it,visited);
        }
    }

}   
int main()
{
    int n =5;
    vector<int>adj[n];
    vector<vector<int>>temp={{0,1},{0,2},{0,3},{2,4}};
    for(int i=0;i<temp.size();i++)
    {
        adj[temp[i][0]].push_back(temp[i][1]);
        adj[temp[i][1]].push_back(temp[i][0]);
    }   
    vector<int>visited(n,0);
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
         if(!visited[i])
        dfs(adj,ans,i,visited);
    }
    for(auto it:ans)
    cout<<it<<" ";

}