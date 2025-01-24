#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// //constant window
// int main()
// {
//     vector<int>arr = {-1,2,3,3,4,5,-1};
//     int k = 4;
//     int n = arr.size();

//     // consecutively
//     int sum=0;
//     for(int i=0;i<k;i++)
//     {
//         sum+=arr[i];
//     }

//     int i=0;int j=k-1;
//     int maxi = sum;     
//     while(j<n-1)
//     {
//         sum-=arr[i];
//         i++;
//         j++;
//         sum+=arr[j];
//         maxi = max(maxi,sum);
//     }
//     cout<<maxi;
// }


// longest substring/subarray
//longest subarray with sum<=k
int main()
{
    // brute force generate all the subarrays

    vector<int>arr = {2,5,1,7,10};
    int k = 14;
    int n = arr.size();
    // int maxlen = 0;

    // for(int i=0;i<n;i++)
    // {
    //     int sum = 0;
    //     for(int j=i;j<n;j++)
    //     {
    //         sum +=arr[j];
    //         if(sum<=k)
    //             maxlen = max(maxlen,j-i+1);
    //         else if(sum>k)
    //         break;
    //     }
    // }
    // cout<<maxlen;




    // better sliding window


    int i=0,j=0;
    int sum = 0;
    int maxi = 0;
    int count = 0;
    while(j<n && i<=j)
    {
        sum+=arr[j];
        if(sum>k)
        {
            sum-=arr[i];
            i++;
        }
        if(sum<=k)
        maxi=max(maxi,j-i+1);
        j++;
    }
    cout<<maxi;
}