#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// search element in a rotated sorted array


int main()
{
    vector<int>arr={4,5,6,7,0,1,2};
    int k = 0;
    int s = 0,e = arr.size()-1;

    while(s<=e)
    {
        int mid = (s+e)/2;

        if(arr[mid]==k)
        {
            cout<<mid;
            break;
        }
        // left part is sorted
        if((arr[s] < arr[mid]))
        {
            if(arr[s] < k && k< arr[mid])
            e = mid-1;
            else
            s=mid+1;
        }
        else
        {
            if(arr[mid]<k && k<arr[e])
            s = mid+1;
            else
            e = mid-1;
        }
    }
    return -1;
}