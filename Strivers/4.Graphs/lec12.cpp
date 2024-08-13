#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include<conio.h>

using namespace std;
// detecting cycle using dfs
void printadj(vector<int>adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
bool dfs(vector<int>adj[],int node,int parent,vector<int>&visited)
{
    visited[node]=1;

    for(auto it:adj[node])
    {
        if(!visited[it])
            if(dfs(adj,it,node,visited)==true)
            {
                return true;
            }
        else if(it!=parent)
        return true;
    }
    return false;
}
int main()
{
    vector<vector<int>>arr = {{0,1},{1,2},{1,4},{4,3},{3,2}};
    int n = 5;
    vector<int>adj[n];
    for(int i=0;i<arr.size();i++)
    {
        adj[arr[i][0]].push_back(arr[i][1]);
        adj[arr[i][1]].push_back(arr[i][0]);
    }
    vector<int>visited(n,0);

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            if(dfs(adj,i,-1,visited)==true)
            return true;

    }
    return false;

}