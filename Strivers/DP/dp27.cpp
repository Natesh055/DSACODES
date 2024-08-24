#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// longest common substring

int main()
{
    string s1 = "abckk", s2 = "abcdef" ;
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    int maxi=INT_MIN;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
            dp[i][j] = 1+ dp[i-1][j-1];
            maxi = max(maxi,dp[i][j]);
            }
            else
            dp[i][j] = 0;
        }
    }
    cout<<maxi;
}