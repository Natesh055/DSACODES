#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// number of hours she eat per hour

int  thours(vector<int>arr,int t)
{
    int myhours=0;
    for(int i=0;i<arr.size();i++)
    {
        myhours+= ceil(double(arr[i])/double(t));
    }
    return myhours;
}
int main()
{
    vector<int>arr = {3,6,7,11};
    int h = 8;
    int maxi = INT_MIN;
    // compute the maximum element
    for(int i=0;i<arr.size();i++)
    {
        maxi = max(maxi,arr[i]);
    }   


    int s = 1;
    int e = maxi;

    int ans=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        int ths = thours(arr,mid);
        
        if(ths<=h)
        {
            ans = mid;
            e = mid-1;
        }
        else
        s = mid+1;
    }
    
cout<<ans;



}