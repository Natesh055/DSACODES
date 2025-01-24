#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// longest increasing subsequence


int solve(vector<int>arr,int index,int last,vector<vector<int>>&dp)
{
    if(index==arr.size())
    return 0;


    // picking the element
    if(dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    int pick = INT_MIN;
    int notpick = solve(arr,index+1,last,dp);
    if(arr[index]>last)
    {
        last = arr[index];
        pick =  1+ solve(arr,index+1,last,dp);
    }
    
    return dp[index][last] = max(pick,notpick);
}
int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    int maxi = INT_MIN;
    for(auto it:arr)
    {
        if(maxi<it)
        maxi = it;
    }
    vector<vector<int>>dp(n,vector<int>(maxi+1,0));
    cout<<solve(arr,1,arr[0],dp);

}