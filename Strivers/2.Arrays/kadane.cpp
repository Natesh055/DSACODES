#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// kadanes algorithm
// maximum subarray sum
// brute force tc O(N)
// int main()
// {
//     vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
//     int n = arr.size();
//     int maxi = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {

//         int sum = 0;
//         // for global

//         for (int j = i ; j < n; j++)
//         {
//             sum += arr[j];
//             maxi= max(maxi,sum);
//         }

//     }
//     cout<<maxi;
// }

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum +=arr[i];
        if(sum>maxi)
        maxi = sum;
        if(sum<0)
        sum = 0;
    }
    cout<<maxi;
}