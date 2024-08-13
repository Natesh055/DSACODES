#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// implement lower and upper bound
// arr[index]>=x lower bound
// O(NlogN)

// int main()
// {
//     vector<int>arr = {1,2,3,3,7,8,9,9,9,11};
//     int x = 9;
//     int n = arr.size();
//     int s = 0;
//     int e =n-1;
//     int ans =n;
//     // lower bound
//     while(s>=e)
//     {
//         int mid = (s+e)/2;
//         if(arr[mid]>=x)
//         {
//             ans = mid;
//             e = mid-1;
//         }
//         else
//         e = mid+1;

//     }
//     cout<<ans;
// }

// upper bound
//  arr[index]>x

// int main()
// {
//     vector<int> arr = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
//     int n = arr.size();
//     int x = 6;
//     int s=0,e=n-1,ans = n;
//     while(s<=e)
//     {
//         int mid = (s+e)/2;
//         if(arr[mid]>x)
//         {
//             ans=mid;
//             e=mid-1;
//         }
//         else
//         s=mid+1;
//     }
//     cout<<ans;
// }

// search insert position similar to lower bound
// int main()
// {
//     vector<int>arr = {1,3,5,6};
//     int k = 2;
//     int n = arr.size();
//     int s = 0;
//     int e =n-1;
//     int ans =n;
//     // lower bound
//     while(s<=e)
//     {
//         int mid = (s+e)/2;
//         if(arr[mid]>=k)
//         {
//             ans = mid;
//             e = mid-1;
//         }
//         else
//         s = mid+1;

//     }
//     cout<<ans;
// }



// floor and ceil in sorted array
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int x = 25;

    int n = arr.size();

    int floor = n;
    int ceil = 0;

    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] >= x)
        {
            ceil = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    s = 0;
    e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] <= x)
        {
           floor = mid;
           s = mid+1;
        }
        else
            e = mid-1;
    }
    cout<<ceil<<" "<<floor;
}