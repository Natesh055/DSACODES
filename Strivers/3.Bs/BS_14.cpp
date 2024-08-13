#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// 1283. Find the Smallest Divisor Given a Threshold

bool compute(vector<int>arr,int k,int x)
{
    int ans = 0;
    for(int i=0;i<arr.size();i++)
    {
        ans+=ceil(double(arr[i])/double(x));
    }
    if(ans<=k)
    return  true;
    return false;

}

int main()
{
    vector<int>arr = {1,2,5,9};
    int k=6;

    int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        maxi = max(maxi,arr[i]);
    }
    int s = 1;
    int e = maxi;
    int result = maxi;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(compute(arr,k,mid)==true)
        {
            result = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    cout<<result;
}