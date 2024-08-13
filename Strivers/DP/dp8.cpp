#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// ninja training
// only 3 activiteies

int solve(vector<vector<int>>arr,int row,int prev,vector<vector<int>>&dp)
{
    if(row==0)
    {
        int maxi = INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(i!=prev)
                maxi = max(maxi,arr[row][i]);
        }   
        return maxi;
    }
    
    if(dp[row][prev]!=-1)
    return dp[row][prev];

    // implementing the logic

    int maxi = INT_MIN;
    for(int i=0;i<3;i++)
    {
        if(i!=prev)
        {
            maxi = max(solve(arr,row-1,i,dp)+arr[row][i],maxi);
        }
    }
    return dp[row][prev]=maxi;
}

int main()
{
    vector<vector<int>>arr = { {10,50,1},
                        {5,100,11} };

    int n = arr.size();
    int maxi  = INT_MIN;    
    vector<vector<int>>dp(n,vector<int>(4,-1));

    // for(int i=0;i<3;i++)
    // {
    //     maxi = max(maxi,solve(arr,n-1,i,dp));
    // }

// cout<<maxi;

    dp[0][0] = max(arr[0][1],arr[0][2]);
    dp[0][1] = max(arr[0][0],arr[0][2]);
    dp[0][2] = max(arr[0][1],arr[0][0]);

    dp[0][3] = max(arr[0][0],max(arr[0][1],arr[0][2]));

    for(int i=1;i<n;i++)
    {
        for(int task=0;task<4;task++)
        {
            dp[i][task] = 0;
            int maxi = 0;
            
        }
    }
}