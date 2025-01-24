#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// unique paths
// m*n matrix
// recutsion tc O(2^n)
int solve(int row,int col,int trow,int tcol,vector<vector<int>>&dp)
{
    if(trow==row&&tcol==col)
    {
        return 1;
    }

    if(trow>row || tcol>col)
    return 0;

    if(dp[trow][tcol]!=-1)
    return dp[trow][tcol];

    int down= solve(row,col,trow+1,tcol,dp),right=solve(row,col,trow,tcol+1,dp);
    return dp[trow][tcol]=down+right;

}
int main()
{
    int m =3, n =7;
    int row = m-1;
    int col = n-1;
    vector<vector<int>>dp(m,vector<int>(n,-1));

    int trow = 0;
    int tcol = 0;
    // cout<<solve(row,col,trow,tcol,dp);

    // i<0 & j<0 can not be implemented

    // O(N*M) O(N*M)
    // for(int i=0;i<m;i++)
    // {
    //     for(int j= 0;j<n;j++)
    //     {
    //         if(i==0&&j==0)
    //         dp[0][0]=1;
    //         else
    //         {
    //             int up=0,left=0;
    //             if(i>0)
    //                 up = dp[i-1][j];

    //             if(j>0)
    //                 left = dp[i][j-1];
    //             dp[i][j] = up+left;
    //         } 
    //     }
    // }

    // space optimzation
    // initialize with col size
    vector<int>prev(n,1);
    for(int i=0;i<m;i++)
    {
        vector<int>temp(n,0);
        for(int j=0;j<n;j++)
        {
            // we cannot go up
            if(i==0&&j==0)
            {
                temp[i]=1;
            }
            // we can only go up
            
            // down row
            else
            {   
                temp[j] = prev[i-1]=temp[j-1];
            }
        }
        prev = temp;
    }

cout<<prev[n-1];




}   