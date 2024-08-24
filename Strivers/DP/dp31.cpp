#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// super sequence


int main()
{
    string s1 = "brute";
    string s2 = "groot";
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
    string temp = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            temp.push_back(s1[i - 1]);
            i--;j--;
        }

        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                temp.push_back(s1[i-1]);
                i--;
                
            }
            else
            {
                temp.push_back(s2[j-1]);
                j--;
            }
        }   
    }
    while (i > 0)
    {
        temp.push_back(s1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        temp.push_back(s2[j - 1]);
        j--;
    }

    reverse(temp.begin(), temp.end());
    cout << temp << endl;

    return 0;
}