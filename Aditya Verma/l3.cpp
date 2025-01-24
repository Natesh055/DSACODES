#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> weight, vector<int> val, int k, int index, vector<vector<int>> &dp)
{
    if (index == 0 || k <= 0)
    {
        return 0;
    }
    if (dp[index][k] != -1)
        return dp[index][k];

    // picking the element
    int pick = 0;
    if (k >= weight[index])
    {
        pick = solve(weight, val, k - weight[index], index - 1, dp) + val[index];
    }
    int notpick = solve(weight, val, k, index - 1, dp);
    return dp[index][k] = max(pick, notpick);
}
int main()
{
    vector<int> weight = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int n = weight.size();
    int k = 7;
    // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    // cout << solve(weight, val, k, n - 1,dp);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= k; i++)
    {
        dp[0][i] = 0;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int pick = 0;
            if(j>=weight[i-1])
                pick = dp[i-1][j-weight[i-1]] + val[i-1];
            int notpick = dp[i-1][j];

            dp[i][j] = max(pick,notpick);

        }
    }
    cout<<dp[n][k];
}