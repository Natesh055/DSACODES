#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// target sum

bool solve(int index, vector<int> arr, int k, vector<vector<int>> &dp)
{
    if (index == 0 || k == 0)
    {
        return k == 0;
    }

    if (dp[index][k] != -1)
        return dp[index][k];

    // picking the element
    bool pick = false;
    if (k >= arr[index])
    {
        pick = solve(index - 1, arr, k - arr[index], dp);
    }
    bool notpick = solve(index - 1, arr, k, dp);
    return dp[index][k] = pick || notpick;
}

int main()
{

    vector<int> arr = {29, 66, 31, 2, 28, 88, 1, 97, 73, 78, 62, 27};
    int k = 582;
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    // cout << solve(n - 1, arr, k,dp);

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool pick = false;
            if (j >= arr[i])
            {
                pick = dp[i-1][j-arr[i]];
            }
            bool notpick = dp[i-1][j];
             dp[i][j] = pick | notpick;
        }
    }
    cout<< dp[n-1][k];
}