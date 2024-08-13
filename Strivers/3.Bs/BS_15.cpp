#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


bool calculate(vector<int>arr,int mid,int days)
{
    int i=0;//array traversing
    for(int j=1;j<=days;j++)
    {
        int temp = mid;
        while(i<arr.size()&& arr[i]<=temp)
        {
            temp=temp-arr[i];
            i++;
        }
    }   
    if(i==arr.size())
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int>weights = {3,2,2,4,1,4};
    int days = 3;
    int sum = 0;
    int maxi = INT_MIN;
    for(auto it:weights)
    {
        maxi = max(maxi,it);
        sum+=it;
    }

    int s = maxi;
    int e = sum;
    int ans=e;
    while(s<=e )
    {
        int mid = (s+e)/2;
        //all are traversed 
        if(calculate(weights,mid,days)==true)
        {
            ans = mid;
            e = mid-1;
        }
        else
        s = mid+1;

    }

cout<<ans;
}