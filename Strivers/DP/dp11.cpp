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

    //  fixed starting point,variable ending point

    vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << (solve(arr, 0, 0, arr.size(), dp));  

    

    for(int i=m-1;i>=0;i--)
    {   
        int mini = INT_MAX;
        for(int j=n-1;j>=0;j--)
        {
            if(i==m-1)
            dp[m-1][j] = arr[m-1][j];
            else
            {
                // justdown
                int jd = dp[i+1][j];

                // diag
                int dg = dp[i+1][j+1];

                mini = min(max(jd,dg)+arr[i][j],mini);

            }
        dp[i][j] = mini;

        }
    }
    cout<<dp[0][0];
}