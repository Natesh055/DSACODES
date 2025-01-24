#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// frog jump with k steps

int solve(vector<int>arr ,int k,int index)
{
    if(index==0)
    return 0;

    int minsteps = INT_MAX;
    for(int i=1;i<=k;i++)
    {
        
        if(index-i>0)
        {
            int jump = solve(arr,k,index-i)+abs(arr[index]-arr[index-k]);
            minsteps = min(minsteps,jump);
        }
    }
    return minsteps;
}
int main()
{
    vector<int>arr =  {2, 5, 2};
    int k = 1;
    // cout<<solve(arr,k,arr.size()-1);
    int n = arr.size();
    vector<int>dp(arr.size(),-1);
    dp[0]=0;
    for(int i=0;i<arr.size();i++)
    {
        int minsteps = INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jmp = dp[i-j]+abs(arr[i]-arr[i-j]);
                minsteps = min(minsteps,jmp);
            }
        }
        dp[i]=minsteps;
    }
cout<<dp[n-1];
}