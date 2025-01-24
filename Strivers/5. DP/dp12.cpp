#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// variable starting and variable ending point

// maximum falling path sum
// O(3^N)

int solve(vector<vector<int>> arr, int row, int col, int m, int n, vector<vector<int>> &dp)
{
    if (col < 0 || col >= n)
    {
        return INT_MIN;
    }
    if (row == 0)
    {
        return arr[row][col];
    }

    if (dp[row][col] != -1)
        return dp[row][col];

    // 3 directions to move
    int maxi = INT_MIN;
    for (int j = -1; j <= 1; j++)
    {
        int ans = solve(arr, row - 1, col + j, m, n, dp);
        if (maxi <= ans)
        {
            maxi = ans;
        }
    }
    return dp[row][col] = maxi + arr[row][col];
}
int main()
{
    vector<vector<int>> arr = {
        {1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int m = arr.size();
    int n = arr[0].size();

    // int maxi = INT_MIN;
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // for(int i=0;i<n;i++)
    // {
    //     maxi = max(maxi, solve(arr,m-1,i,m,n,dp));
    // }
    // cout<<maxi;

    // tabulation
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // for(int i=0;i<n;i++)
    // {
    //     dp[m-1][i] = arr[m-1][i];
    // }

    // for(int i=m-2;i>=0;i--)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         int maxi = INT_MIN;
    //         for(int k=-1;k<=1;k++)
    //         {
    //             // bounds me hai
    //             if(j+k>0 && j+k<=m)
    //             {
    //                 maxi = max(maxi,dp[i+1][j+k]+arr[i][j+k]);
    //             }
    //         }
    //         dp[i][j]=maxi;

    //     }
    // }
    // int result = INT_MIN;
    // for (int i = 0; i < n; i++) {
    //     result = max(result, dp[0][i]);
    // }

    // cout << result << endl;

    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        prev[i] = arr[0][i];
    }


    for(int i=0;i<n;i++)
    {
        vector<int>temp(n,0);
        for(int j=0;j<n;j++)
        {
            int maxi = INT_MIN;
            for(int k=-1;k<=1;k++)
            {
                int cols = k+j;

                if(cols>0 && cols<=m)
                {
                    maxi = max(maxi,prev[cols]+arr[i][j]);
                }
            }
            temp[j] = maxi;
        }   
        prev= temp;
    }
    for(auto it:prev)
    cout<<it<<" ";
}