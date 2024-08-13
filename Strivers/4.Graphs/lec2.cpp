#include<iostream>
#include<vector>
using namespace std;

// adjacency list
int main()
{
    int n = 5 ;
    vector<int>adj[n+1];
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
}