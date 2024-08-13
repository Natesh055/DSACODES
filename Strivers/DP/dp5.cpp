#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// house robber

int solve(vector<int> arr, int index, vector<int> &dp)
{
    if (index == 0)
        return arr[index];

    if(index<0)
    return 0;

    if(dp[index]!=-1)
    return dp[index];
    // it can only move 2 steps
    int pick =solve(arr, index - 2, dp) + arr[index];

    int notpick = solve(arr, index - 1, dp)+0;

    return dp[index] = max(pick, notpick);
}
int main()
{
    vector<int> arr = {1};
    int n = arr.size();
    vector<int> dp(n, -1);
    // cout << solve(arr, n - 1, dp);
    // tabulation
    // dp[0] = arr[0];
    // int neg = 0;
    // for(int i=1;i<n;i++)
    // {
    //     int pick = arr[i];
    //     if(i>1)
    //     pick += dp[i-2];

    //     int notpick = dp[i-1];

    //     dp[i] = max(pick,notpick);
    // }   
    // cout<<dp[n-1];

    // space optimization

    int prev =arr[0];
    int prev2=0;
    int ans = 0;
    for(int i=1;i<n;i++)
    {
        int pick = arr[i];
        if(i>1)
        pick+=prev2;

        int notpick = prev+0;

        ans = max(pick,notpick);
        prev2=prev;
        prev=ans;
    }
    cout<<ans;
}