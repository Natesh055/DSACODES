#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// minimum insertions to make a string pallindrome

int solve(string s1)
{
    string s2 = "";
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        s2 = s2 + s1[i];
    }
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{
    string s1 = "codingninjas";
    int ans = solve(s1);

    cout<<s1.length()-ans;
}
