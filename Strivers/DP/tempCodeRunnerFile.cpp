
{
    string s1 = "abcde", s2 = "abc";
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

    // printing the lcs
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
            if(dp[i-1][j]>dp[i][j])
            i--;
            else
            j--;
        }   
    }
    reverse(temp.begin(),temp.end());
    cout<<temp;
}