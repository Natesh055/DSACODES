#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

// brute force TC O(N3)
// int main()
// {
//     vector<int>arr = {-1,0,1,2,-1,-4};
//     int n = arr.size();
// vector<vector<int>>ans;
// set<vector<int>>st;
//     for(int i=0;i<n;i++)
//     {
//         vector<int>temp;
//         for(int j=i+1;j<n;j++)
//         {
//             for(int k=j+1;k<n;k++)
//             {
//                 if(arr[i]+arr[j]+arr[k]==0)
//                 {
//                     temp.push_back(arr[i]);
//                     temp.push_back(arr[j]);
//                     temp.push_back(arr[k]);
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);

//                 }

//             }
//         }
//     }
//     ans = {st.begin(),st.end()};

// }

// better solution
// TC O(N2* LogN)
// int main()
// {
//     vector<int>arr = {-1,0,1,2,-1,-4};
//     int n = arr.size();
//     set<vector<int>>st;
//     for(int i=0;i<n;i++)
//     {
//         set<int>hashst;
//         for(int j=i+1;j<n;j++)
//         {
//             int  sum = -(arr[i]+arr[j]);
//             if(hashst.find(sum)!=hashst.end());
//             {
//                 vector<int>temp = {arr[i],sum,arr[j]};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashst.insert(arr[j]);

//         }
//     }
// }

// 2 pointer approach
// int main()
// {
//     vector<int> arr = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
//     vector<vector<int>> ans;
//     int n = arr.size();

//     if (n < 3)
//         return ans; // Early return if there are less than 3 elements

//     sort(arr.begin(), arr.end()); // Sort the array

//     for (int i = 0; i < n - 2; i++)
//     { // Loop up to n-2 to leave space for j and k
//         if (i > 0 && arr[i] == arr[i - 1])
//             continue; // Skip duplicate elements

//         int j = i + 1;
//         int k = n - 1;

//         while (j < k)
//         {
//             int sum = arr[i] + arr[j] + arr[k];

//             if (sum < 0)
//             {
//                 j++;
//             }
//             else if (sum > 0)
//             {
//                 k--;
//             }
//             else
//             {
//                 ans.push_back({arr[i], arr[j], arr[k]});
//                 j++;
//                 k--;

//                 // Skip duplicates for j
//                 while (j < k && arr[j] == arr[j - 1])
//                     j++;

//                 // Skip duplicates for k
//                 while (j < k && arr[k] == arr[k + 1])
//                     k--;
//             }
//         }
//     }
// }

