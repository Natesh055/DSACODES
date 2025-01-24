#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// unique paths 2
int solve(vector<vector<int>>arr,int row,int col)
{
    if(row==0&&col==0)
    return 1;

    if(row<0||col<0)
    {
        return 0;
    }
    if(arr[row][col]==1)
    return 0;

    int up = solve(arr,row-1,col);
    int left = solve(arr,row,col-1);
    return up+left;
}
int main()
{
    vector<vector<int>>arr = {{0,1},{0,0}};
    int n = arr.size();
    int m = arr[0].size();
    // cout<<solve(arr,n-1,m-1);

    // tabulation
    vector<int>prev(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int>temp(m,0);
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
            temp[i]=1;


            else if(arr[i][j]==1)
            {
                temp[j]=0;
            }
            else
            {
                temp[j] = temp[j-1] + prev[j];
            }
        }
        prev= temp;
    }
    cout<<prev[m-1];
}