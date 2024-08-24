#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// recursion O(2^N) O(N)
// memoization O(N*k) scO(N*k)+O(N)
bool solve1(vector<int> arr, int index, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;

    if (index == 0)
        return (k == arr[0]);

    if (dp[index][k] != -1)
        return dp[index][k];

    bool nottake = solve1(arr, index - 1, k, dp);
    bool take = false;

    if (arr[index] <= k)
    {
        take = solve1(arr, index - 1, k - arr[index], dp);
    }
    return dp[index][k] = take || nottake;
}

void solve(vector<int> arr, int k, int index, vector<int> &temp, vector<vector<int>> &ans)
{
    if (index <= 0)
    {
        if (arr[index] == k)
        {
            temp.push_back(arr[0]);
            ans.push_back(temp);
        }
        else
            return;
    }

    if (k == 0)
        ans.push_back(temp);

    // pick the element
    if (k >= arr[index])
    {
        temp.push_back(arr[index]);
        solve(arr, k - arr[index], index - 1, temp, ans);
    }
    // do not pick the element
    temp.pop_back();
    solve(arr, k, index - 1, temp, ans);
}
int main()
{
    vector<int> arr = {1, 3, 2, 4};
    int n = arr.size();

    int k = 4;
    // vector<int> temp;
    // vector<vector<int>>ans;
    // solve(arr, k, arr.size() - 1, temp,ans);

    // for(int i=0;i<ans.size();i++)
    // {
    //     for(auto it:ans[i])
    //     cout<<it<<" ";
    //     cout<<endl;
    // }
    // vector<vector<int>>dp(arr.size()+1,vector<int>(k+1,-1));
    // cout<< solve1(arr,arr.size()-1,k,dp);

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool nottake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];

            dp[i][j] = take || nottake;
        }
    }

    // cout << dp[n - 1][k];






    // sc O(target) 
    // memoization
    
    vector<int>prev(k+1,0),cur(k+1,0);
    prev[0]=cur[0]=true;
    prev[arr[0]]=true;
     for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool nottake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];

            cur[j] = take || nottake;
        }
        prev=cur;
    }
    cout<<prev[k];
}