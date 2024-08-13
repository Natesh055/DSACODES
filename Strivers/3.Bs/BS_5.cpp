#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// search element in a rotated sorted array 2

int main()
{
    vector<int>arr ={2,5,6,0,0,1,2};
    int k = 0;

    int s = 0,e = arr.size()-1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==k){
        cout<<1;break;
        }

        if(arr[mid] == arr[s] && arr[mid] == arr[e])
        {
            s++;
            e--;
            continue;
        }
        // now we got the left half sorted
        if(arr[s] < arr[mid])
        {
            // now the element is in the left half
            if(arr[s] < k && k < arr[e])
            e = mid-1;
            else
            s = mid+1;
        }
        else
        {
            // the element is in the right half
            if(arr[e] > k && k > arr[mid])
            {
                s = mid+1;
            }
            else
            e = mid-1;
        }
    }
    return 0;
}