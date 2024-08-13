#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// frog jump
// try all possible ways
// TC O(N)
// SC O(1)+O(N)//stack space
int solve(vector<int>arr,int index,vector<int>&dp)
{
    if(index == 0 )
    return 0;

    if(dp[index]!=-1)
    return dp[index];

    int left = abs(arr[index]-arr[index-1])+solve(arr,index-1,dp);
    int right = INT_MAX;
    if(index>1)
    int right = abs(arr[index]-arr[index-2])+solve(arr,index-2,dp);
    return dp[index]=min(left,right);

}

int main()
{
    // express in terms of index 
    // do all stuff on that index
    //take minimum of all stuff
    vector<int>arr = {30,10,60,50};
    int n = arr.size();
    // vector<int>dp(n,-1);
    // recursion is to reach n-1 index from 0 index using minimum energy
    // cout<<solve(arr,n-1,dp);

    // tabulation
    // bottom up
    // bottom case
    vector<int>dp(n,0);

    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int fs = dp[i-1]+abs(arr[i]-arr[i-1]);
        int ss = INT_MAX;
        if(i>1)
        ss = dp[i-2]+abs(arr[i]-arr[i-2]);

        dp[i] = min(fs,ss);
    }
    // cout<<dp[n-1];

    // reducint the space 
    int a = 0;
    int b = 0;
    int c = 0;
    for(int i=1;i<n;i++)
    {
        int fs = b+abs(arr[i]-arr[i-1]);
        int ss = INT_MAX;
        if(i>1)
        ss = c+abs(arr[i]-arr[i-2]);
        a = min(fs,ss);
        c=b;
        b=a;
    }
    cout<<a;

}