#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// maximum product subarray
// TC O(N3)
// SC O(1)
// int main()
// {
//     vector<int> arr = {2, 3, -2, 4};
//     int n = arr.size();

//     int maxi = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int prod = 1;
//             for (int k = i; k <= j; k++)
//             {
//                 prod = prod * arr[k];
//             }
//             maxi = max(maxi, prod);
//         }
//     }
//     cout << maxi;
//     return 0;
// }

// O(N2)
// O(1)
int main()
{
    vector<int> arr = {0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0};
    int n = arr.size();

    long long int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long int prod = 1;
        for (int j = i; j < n; j++)
        {
            prod = prod * arr[j];
            maxi = max(maxi, prod);
        }
    }
    cout << maxi;
    return 0;
}

