#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// minimum days to make bouquie

bool possible(vector<int>arr,int x,int k,int m)
{
    int count = 0,nob=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<=x)
        {
            count++;
        }
        else
        {
            nob+=count/k;
            count=0;
        }
        nob+=count/k;
    }
    if(nob>=m)
    return true;
    return false;
}



int main()
{
    vector<int>arr = {1,10,3,10,2};
    int  m = 3, k = 1; //k is adjacent flowers requireed m is no of bouquets

    // finding the maximum days
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for(int i=0;i<arr.size();i++)
    {
        maxi = max(arr[i],maxi);
        mini = min(arr[i],mini);
    }

    int s = mini;
    int e = maxi;
    int ans =e;


    while(s<=e )
    {
        int mid = (s+e)/2;
        if(possible(arr,mid,k,m)==true)
        {
            e = mid-1;
            ans = mid;
        }
        else
        s=mid+1;
    }
cout<<ans;
}