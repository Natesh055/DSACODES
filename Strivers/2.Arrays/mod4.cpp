#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// longest subarray with givenn sum
// 1. Brute Force generate all subarrays
// tc O(N3) space complexity O(1)
// int main()
// {
//     vector<int>arr = {1,2,3,1,1,1,1,4,2,3};
//     int t=3;
//     int n = arr.size();
//     int len = 0;

//     for(int i=0;i<n;i++)
//     {
//         vector<int>temp;
//         for(int j=i;j<n;j++)
//         {
//             int sum = 0;
//             for(int k = i;k<=j;k++)
//             {
//                 sum+=arr[k];
//             }
//             if(sum == t)
//             {
//                 len = max(len ,j-i+1);
//             }
//         }
//     }
//     cout<<len;

// }

// better
// o(n2)

// int main()
// {
//     vector<int>arr = {1,2,3,1,1,1,1,4,2,3};
//     int t=3;
//     int n = arr.size();
//     int len = 0;

//     for(int i=0;i<n;i++)
//     {
//         int sum = 0;

//         for(int j=i;j<n;j++)
//         {
//             sum +=arr[j];

//             if(sum==t)
//             len = max(len,j-i+1);
//         }
//     }
//     cout<<len;
// }

// hashing

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int t = 3;
    int n = arr.size();
    int len = 0;
}
