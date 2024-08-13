#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;



int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};

    int n = grid.size();
    if (n == 0 || grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});

    vector<vector<int>> visited(n, vector<int>(n, INT_MAX));
    visited[0][0] = 0;
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();   


        if (x == n - 1 && y == n - 1)
            cout<< distance;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nrow = x + i;
                int ncol = y + j;
                

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0)
                {
                    if (visited[nrow][ncol] > distance + 1)
                    {
                        // cout<<nrow<<" "<<ncol;
                        // cout<<endl;
                        visited[nrow][ncol] = distance + 1;
                        pq.push({distance+1,{nrow,ncol}});
                    }
                }
            }
        }
        // for(int i=0;i<visited.size();i++)
        // {
        //     for(int j=0;j<visited.size();j++)
        //     cout<<visited[i][j]<<" ";
        //     cout<<endl;
        // }
    }

}