#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool solve(string s, string p, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;

    if (j < 0 && i >= 0)
    {
        return false;
    }

    if (i < 0 && j >= 0) // it has to be all stars,not a single character
    {
        for (int k = j; k >= 0; k--)
            if (p[k] != '*')
                return false;
        return true;
    }

    if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
    }

    if (p[j] == '*')
    {
        return dp[i][j] = solve(s, p, i, j - 1, dp) || solve(s, p, i - 1, j, dp);
    }

    if (s[i] != p[j])
        return false;

    return false;
}

int main()
{
    string s = "aa", p = "?a";
    int m = s.length(), n = p.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // cout << solve(s, p, m - 1, n - 1, dp);

    dp[0][0] = 1;

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        bool flag =true;
        for (int k = i; k >= 1; k--)
        {

            if (p[k] != '*')
            {
                flag = false;
                break;
            }

        }
        dp[0][i]=flag;

    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i] == p[j] || p[j] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (p[j] == '*')
            {
                return dp[i][j]= dp[i-1][j]||dp[i][j-1];
            }

            if (s[i] != p[j])
            dp[i][j] =  false;
        }
    }
    cout<<dp[m][n];
}