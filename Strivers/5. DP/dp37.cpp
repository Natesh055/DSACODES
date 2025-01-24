#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// best time to buy and sell stocks 3
// only 2 times we can buy and sell

int solve(vector<int> arr, int index, bool buy, int cap, vector<vector<vector<int>>> &dp)
{
    if (index == arr.size() || cap == 0)
        return 0;
    if (buy)
    {
        return dp[index][buy][cap] = max(-arr[index] + solve(arr, index + 1, 0, cap, dp), solve(arr, index + 1, 1, cap, dp));
    }

    else
    {
        return dp[index][buy][cap] = max(arr[index] + solve(arr, index + 1, 1, cap - 1, dp), solve(arr, index + 1, 0, cap, dp));
    }
}

int main()
{
    vector<int> arr = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = arr.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
    // cout << solve(arr, 0, 1, 2, dp);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= 1; j++)
    //     {
    //         dp[i][j][0] = 0;
    //     }
    // }

    // for (int i = 0; i <= 1; i++)
    // {
    //     for (int j = 0; j <= 2; j++)
    //     {
    //         dp[n - 1][i][j] = 0;
    //     }
    // }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 1; k <= 2; k++)
            {
                if (j)
                {
                     dp[i][j][k] = max(-arr[i] + dp[i+1][0][k], dp[i+1][1][k]);
                }

                else
                {
                 dp[i][j][k] = max(arr[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
                }
            }
        }
    }
}