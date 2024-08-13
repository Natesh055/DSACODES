#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// merge 2 sorted arrays without extra space
// brute force
// time cpmplexity O(2(N+M)) SC O(N+M)
// int main()
// {
//     vector<int> arr1 = {1, 3, 5, 7};
//     int m = arr1.size();
//     vector<int> arr2 = {0, 2, 6, 8, 9};
//     int n = arr2.size();

//     int i = 0, j = 0;
//     vector<int> ans;
//     while (i < m && j < n)
//     {
//         if (arr1[i] > arr2[j])
//             ans.push_back(arr2[j++]);

//         else
//             ans.push_back(arr1[i++]);
//     }

//     while (i < m)
//         ans.push_back(arr1[i++]);

//     while (j < n)
//         ans.push_back(arr2[j++]);

//     // for (auto it : ans)
//     //     cout << it << " ";

//     int count=0;
//     for(int i=0;i<m;i++)
//     {
//         arr1[i]=ans[count++];
//     }
//     for(int j=0;j<n;j++)
//     {
//         arr2[j] = ans[count++];
//     }
//     for (auto it : arr1)
//         cout << it << " ";

//         for (auto it : arr2)
//         cout << it << " ";
// }

// optimal solution
// TC O(min(m,n)+nlogn+mlogn)
// int main()
// {
//     vector<int> arr1 = {1,2,3,0,0};
//     int m = 3;
//     vector<int> arr2 = {2,5,6};
//     int n = 3;
    
//     arr1.resize(m);
//     arr2.resize(n);
//     int i=m-1;
//     int j=0;
//     while(i>=0 && j<n)
//     {
//         if(arr1[i]>=arr2[j])
//         swap(arr1[i--],arr2[j++]);
//         else break;
//     }
//     sort(arr1.begin(),arr1.end());
//     sort(arr2.begin(),arr2.end());

//     for(int i=m;i<m+n;i++)
//     {
//         arr1.push_back(arr2[i-m]);
//     }
//     for(auto it:arr1)
//     cout<<it<<" ";
    

// }


w