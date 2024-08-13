#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

// number off subarrays with given xor k
// brute force tcO(N3)
// int main()
// {
//     vector<int>arr = {4,2,2,6,4};
//     int n = arr.size();
//     int k =6;
//     int count = 0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             int x = 0;

//             for(int k=i;k<=j;k++)
//             {
//                 x = x^arr[k];
//             }
//             if(x==k)
//             count++;
//         }
//     }
//     cout<<count;
// }

// better solution
// TC O(N2)
// int main()
// {
//     vector<int> arr = {4, 2, 2, 6, 4};
//     int n = arr.size();
//     int k = 6;
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int x = 0;
//         for (int j = i; j < n; j++)
//         {
//             x = x ^ arr[j];
//         }
//         if (x == k)
//         {
//             count++;
//         }
//     }
//     cout << count;
// }



// optimal solution
int main()
{
    vector<int>arr = {4,2,2,6,4};
    int k=6;
    int n = arr.size();
    
}