#include <iostream>

using namespace std;
// number of subsets with given difference

int main()
{
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;

    int n = arr.size();
    int tsum = 0;
    for (auto it : arr)
        tsum += it;

    int sums1 = (diff + tsum) / 2;

    // now we have to count the number of times my subset is equal to sums1
    // cout << sums1;

    // now counting the number of subsets with sum k

    int k = sums1;
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
    cout<< dp[n - 1][k];
}