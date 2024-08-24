#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// distinct subsequences

int solve(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;

    if (i < 0)
    {
        return 0;
    }

    if (s[i] == t[j])
    {
        return dp[i][j] = solve(s, t, i - 1, j - 1, dp) + solve(s, t, i - 1, j, dp);
    }
    else
        return dp[i][j] = solve(s, t, i - 1, j, dp);
}

int main()
{
    string s = "rabbbit", t = "rabbit";
    int m = s.length();
    int n = t.length();
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    //    cout<< solve(s,t,m-1,n-1,dp);

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }
for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[m][n];
    return 0;
}