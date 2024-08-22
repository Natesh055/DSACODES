#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// traingle fixed start and end point

int solve(vector<vector<int>> arr, int row, int col, int m, vector<vector<int>> &dp)
{
    if (row == m - 1)
    {
        // int mini = INT_MAX;
        // for (int i = 0; i < arr[row].size(); i++)
        // {
        //     mini = min(mini, arr[row][i]);
        // }

        // return mini;
        return arr[row][col];
    }
    if (dp[row][col] != -1)
        return dp[row][col];

    int mini = INT_MAX;

    // next row,
    int n = solve(arr, row + 1, col, m, dp);
    // n row nol
    int c = solve(arr, row + 1, col + 1, m, dp);
    mini = min(min(n, c) + arr[row][col], mini);

    return dp[row][col] = mini;
}
int main()
{
    // vector<vector<int>> arr = {{-1}, {2, 3}, {1, -1, -3}};
    vector<vector<int>> arr = {{-10}};
        int m = arr.size();
        int n = arr[m - 1].size();

    //     //  fixed starting point,variable ending point

    //     // vector<vector<int>> dp(m, vector<int>(n, -1));
    //     // cout << (solve(arr, 0, 0, arr.size(), dp));

        vector<vector<int>> dp(m, vector<int>(m, -1));

    //     for(int i=0;i<n;i++)
    //     {
    //         dp[n-1][i] = arr[n-1][i];
    //     }

    //     for(int i=n-2;i>=0;i--)
    //     {
    //         for(int j=i;j>=0;j--)
    //         {
    //             int d = dp[i+1][j]+arr[i][j];
    //             int dg = dp[i+1][j+1]+arr[i][j];

    //             dp[i][j] = min(d,dg);

    //         }
    //     }
    // cout<<dp[0][0];

    // space optimization

    vector<int>prev(m,0);
    for (int i = 0; i < n; i++)
    {
        prev[i] =  arr[n - 1][i];
    }

        vector<int>temp(m,0);
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = prev[j] + arr[i][j];
            int dg = prev[j+1] + arr[i][j];

            temp[j] = min(d, dg);
        }
        temp = prev; 
    }
    cout<<prev[0];
}