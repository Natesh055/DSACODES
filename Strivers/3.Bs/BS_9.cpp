#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    vector<int>arr = {1,2,1,3,5,6,4};
    //                0,1,2,3,4,5,6
    int n = arr.size();
    
    if(n==1)
    return arr[0];


    if(n==2){
        if(arr[0]>arr[1])
        return 0;
        return 1;
    }

    

    if(arr[1]<arr[0])
    return 0;

    if(arr[n-1] > arr[n-2])
    return n-1;

    int s = 1, e=n-2;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid] >=arr[mid-1] && arr[mid]>=arr[mid+1])
        {
            cout<<mid;
            break;
        }
        // probable answer
        if(arr[mid] >=arr[mid-1])
        s = mid+1;

        else
        e = mid-1;
    }
    cout<<-1;

}