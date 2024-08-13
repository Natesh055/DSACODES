#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main()
{
    vector<vector<int>> arr = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> visited(m, vector<int>(n, INT_MAX));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({arr[0][0], {0, 0}});

    visited[0][0] = 0;
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == m - 1 && y == n - 1)
        {
            cout << distance;
            cout << endl;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n )
            {
                int a = min(distance,abs(arr[nrow][ncol] - arr[x][y]));
                if (visited[nrow][ncol] > a)
                {
                    visited[nrow][ncol] = a;
                    pq.push({a, {nrow, ncol}});
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}