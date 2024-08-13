#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int>arr = {3,4,5,1,2};
    int mini = INT_MAX;
    int s = 0;
    int e = arr.size()-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        // the array is sorted
        if(arr[s] <=arr[e])
        {
            mini = min(arr[s],mini);
            break;
        }
        if(arr[s] <=arr[mid])
        {
            mini = min(arr[s],mini);
            s = mid+1;
        }
        else
        {
            mini = min(arr[mid],mini);
            e = mid-1;
        }

    }
    if(arr[0]==mini)
    cout<<"YES";

    else 
    cout<<"False";




}