#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// count inversions i.e. left element to be greater than right element
// brute force O(N2) SC O(1)
// int main()
// {
//     vector<int> arr = {5, 3, 2, 4, 1};
//     int n = arr.size();
//     int count = 0;
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 cout << arr[i] << " " << arr[j] << endl;
//                 count++;
//             }
            
//         }
//     }
//     cout << count;
// }

// optimal solution
int main()
{
    vector<int>arr ={2,3,5,6};
    // vector<int>arr ={2,2,4,4,8};
    int n = arr.size();
}