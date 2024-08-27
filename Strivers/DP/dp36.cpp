#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// best time to buy and sell stocks 2 
int solve(vector<int> arr, bool buy, int index, vector<vector<int>> dp)
{
    if (index == arr.size())
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];
    if (buy)
    {
        return dp[index][buy] = max(-arr[index] + solve(arr, !buy, index + 1, dp), solve(arr, buy, index + 1, dp));
    }
    else
    {
        return dp[index][buy] = max(arr[index] + solve(arr, !buy, index + 1, dp), solve(arr, buy, index + 1, dp));
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // cout << solve(arr, 1, 0, dp);
    vector<vector<int>> dp(n+1, vector<int>(2,0));
    for (int i = 0; i <= 1; i++)
    {
        dp[n][i] = 0;
    }

    for (int i = n-1; i>=0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                 profit = max(-arr[i] + dp[i+1][!buy], dp[i+1][buy]);
            }
            else
            {
                profit = max(arr[i] + dp[i+1][!buy],dp[i+1][buy]);
            }
            dp[i][buy]=profit;
        }
    }
    cout<<dp[0][1];
}