#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// number of provinces
void dfs(vector<int> adj[], vector<int> &visited, int node)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
            dfs(adj, visited, it);
    }
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int n = matrix.size();
    vector<int> visited(n, 0);
    int count = 0;


    // to create adjacency list from matrix
    vector<int> adj[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && matrix[i][j] == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            dfs(adj, visited, i);
        }
    }
    cout << count;
}