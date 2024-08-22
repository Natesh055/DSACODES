#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// recursion O(3^N*3^N) tc
// sc O(N)stack space +


// memo tc: O(N*M*M*9)

int solve(vector<vector<int>> arr, int r1, int c1, int c2, int m, int n,vector<vector<vector<int>>>&dp)
{
    // out of bound case
    if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
        return -1e8;

    // base case
    if (r1 == m - 1)
    {
        if (c1 == c2)
            return arr[r1][c1];
        return arr[r1][c1] + arr[r1][c2];
    }
    if(dp[r1][c1][c2]!=-1)
    return dp[r1][c1][c2];

    if (c1 == c2)
    {
        return arr[r1][c1];
    }

    int maxi = INT_MIN;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (c1 == c2)
                maxi = max(maxi, arr[r1][c1] + solve(arr, r1 + 1, c1 + i, c2 + j, m, n,dp));
            else
                maxi = max(maxi, arr[r1][c1] + arr[r1][c2] + solve(arr, r1 + 1, c1 + i, c2 + j, m, n,dp));
        }
    }

    return dp[r1][c1][c2]=maxi;
}
int main()
{
    vector<vector<int>> arr = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    // cout << solve(arr, 0, 0, n - 1, m, n,dp);

    // applying tabulation
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                dp[n-1][i][j] = arr[n-1][j];
            }
            else
            dp[n-1][i][j] = arr[n-1][i]+arr[n-1][j];
        }
    }
}