#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// subarrays with sum k
// contigous part of array
// brute force
// TC O(N2)
// int main()
// {
//     vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
//     int k = 3;
//     int n = arr.size();
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum == k)
//                 count++;
//         }
//     }
// }




// better 
// using prefix sum
int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    int n = arr.size();
    
}