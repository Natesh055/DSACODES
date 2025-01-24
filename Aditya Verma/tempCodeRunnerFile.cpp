int sum = 0;
    for (auto it : arr)
        sum += it;

    if (sum % 2 != 0)
        return 0;

    // return solve(arr,arr.size()-1,sum/2);
    int n = arr.size();
    int k = sum/2;

    vector<vector<bool>>dp(n,vector<bool>(k+1,false));





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