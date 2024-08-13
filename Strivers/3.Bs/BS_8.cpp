#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int>arr = {1,1,2,3,3,4,4,8,8};
    int n = arr.size();
    int s = 1,e = n-2;

    if(arr[0]!=arr[1])return arr[0];

    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    while(s<=e)
    {
        int mid = (s+e)/2;
        // single element
        if(arr[mid]!= arr[mid-1] && arr[mid]!=arr[mid+1]){
            cout<<mid;
            break;
        }

        // eliminate the space where the element is not present
        // in right half
        if((mid%2==0 && arr[mid]==arr[mid+1])||(mid%2==1 && arr[mid-1]==arr[mid]))
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }

    }

cout<<-1;
}