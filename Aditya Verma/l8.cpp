#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// equal sum patrition

bool solve(vector<int> arr, int index)
{
    // if(k==0)
    // return true;
    // if(index ==0)
    // return k==arr[0];

    // //pick the element
    // bool pick = false;
    // if(arr[index]>=k)
    // pick = solve(arr,index-1,k-arr[index]);

    // bool notpick = solve(arr,index-1,k);

    int sum = 0;
    for (auto it : arr)
        sum += it;

    if (sum % 2 != 0)
        return false;

    // return solve(arr,arr.size()-1,sum/2);
    int n = arr.size();
    int k = sum / 2;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool pick = false;
            if (j >= arr[i])
            {
                pick = dp[i - 1][j - arr[i]];
            }
            bool notpick = dp[i - 1][j];
            dp[i][j] = pick | notpick;
        }
    }
    return dp[n - 1][k];
}

int main()
{
    vector<int> arr = {100,4,6};
    cout<<solve(arr,arr.size()-1);
}