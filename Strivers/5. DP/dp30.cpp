#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// minimum insertion and deletion to convert a to b
int solve(string s1,string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j] = 1+ dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string s1 = "cue";
    string s2 = "djo";
    int lcs = solve(s1,s2);
     int m = s1.length();
    int n = s2.length();
    cout<< m + n - 2 * lcs;
}