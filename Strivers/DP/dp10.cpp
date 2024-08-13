#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// minimum path sum
int solve(vector<vector<int>> arr, int row, int col, vector<vector<int>> &dp)
{
    // reaching the base case
    if (row == 0 && col == 0)
        return arr[row][col];

    if (row < 0 || col < 0)
        return INT_MAX;

    if (dp[row][col] != -1)
        return dp[row][col];
    int up = solve(arr, row - 1, col, dp);
    int left = solve(arr, row, col - 1, dp);

    return dp[row][col] = min(up, left) + arr[row][col];
}

int main()
{
    // vector<vector<int>>arr= {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}};
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout<<solve(arr,m-1,n-1,dp);

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(i==0&&j==0)
    //         dp[i][j]=arr[i][j];

    //         else
    //         {
    //             int up = INT_MAX,left=INT_MAX;
    //             if(i>0)
    //             up = dp[i-1][j];

    //             if(j>0)
    //             left = dp[i][j-1];

    //             dp[i][j] = min(up,left)+arr[i][j];

    //         }
    //     }
    // }

    // cout<<dp[m-1][n-];

    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = arr[0][0];

            else
            {
                int up = arr[i][j], left = arr[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;

                if (j > 0)
                    left += temp[j - 1];
                else
                    left += 1e9;

                temp[j] = min(up, left);
            }
        }
        prev = temp;
    }
    cout << prev[m - 1];
}
