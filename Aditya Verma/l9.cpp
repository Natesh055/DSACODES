#include <iostream>
using namespace std;
// count subsets of given subset k

int solve(vector<int> arr, int index, int k, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return 1;
    }
    if (index == 0)
        return arr[0] == k;

    // pick the element

    if (dp[index][k] != -1)
        return dp[index][k];

    int pick = 0;
    if (k >= arr[index])
        pick = solve(arr, index - 1, k - arr[index], dp);

    int notpick = solve(arr, index - 1, k, dp);
    return dp[index][k] = pick + notpick;
}

int main()
{
    vector<int> arr = {28, 4, 3, 27, 0, 24, 26};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    // cout << solve(arr, n - 1, k, dp);

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    } 
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            int pick = 0;

            if (target >= arr[index])
                pick = dp[index - 1][target - arr[index]];

            int notpick = dp[index - 1][target];

            dp[index][target] = pick + notpick;
        }
    }
    cout << dp[n - 1][k];
}