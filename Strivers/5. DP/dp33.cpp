#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// edit distance

int solve(string s1, string s2, int i, int j,vector<vector<int>>&dp)
{

    if (i < 0)
        return j + 1;

    if (j < 0)
        return i + 1;

    if (s1[i] == s2[j])
        return dp[i][j] =solve(s1, s2, i - 1, j - 1,dp);

    // for inserting
    int insert = solve(s1, s2, i, j - 1,dp);

    int del = solve(s1, s2, i - 1, j,dp);

    int replace = solve(s1, s2, i - 1, j - 1,dp);

    return dp[i][j] = 1 + min(insert, min(del, replace));
}
int main()
{
    string s1 = "intention", s2 = "execution";
    int m = s1.length();
    int n = s2.length();
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // cout << solve(s1, s2, m - 1, n - 1,dp);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i=0;i<=m;i++)
    {
        dp[i][0] = i;
    }
    for(int i=0;i<=n;i++)
    {
        dp[0][i] = i;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j] = dp[i-1][j-1];
            else
            dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    cout<<dp[m][n];
}