#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// finding first and last occurence of the elemenet

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;

    int s = 0;
    int e = arr.size() - 1;
    int first = -1, last = -1;
    vector<int> temp;
    // to get the first element
    // implement lower bound
    while(s<=e)
    {       
        int mid = (s+e)/2;
        if(arr[mid] >= target)
        {
            e = mid-1;
            first = mid;
        }
        else
        s = mid+1;
    }   
    s = 0,e = arr.size()-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid] > target)
        {
            e = mid-1;
            last = mid;
        }
        else
        s=mid+1;
    }
    cout<<first<<" "<<last;
}