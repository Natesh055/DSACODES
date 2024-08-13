#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS
// directed graphs
int main()
{
    int n =5;
    vector<int> adj[n];
    queue<int>q;
    vector<vector<int>> temp = {{0, 1}, {0, 2}, {0, 3}, {2, 4}}; //connected components
    for (int i = 0; i < temp.size(); i++)
    {
        adj[temp[i][0]].push_back(temp[i][1]);
    }
    int s = 0;
    q.push(s);
    vector<int>visited(n,0);
    visited[s]=1;
    vector<int>bfs;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }
        bfs.push_back(node);
    }
    for(auto it:bfs)
    cout<<it<<" ";
}