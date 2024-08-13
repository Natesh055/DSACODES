#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// 2 sum problem
// brute force tc o(n2)
// int main()
// {
//     vector<int> arr = {2, 6, 5, 8, 11};
//     int k = 14;
//     int n = arr.size();
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[i] + arr[j] == k)
//             {
//                 ans.push_back(arr[i]);
//                 ans.push_back(arr[j]);
//             }
//         }
//     }
//     for (auto it : ans)
//         cout << it << " ";
// }

// better solution hashing
// tc O(N*logN) sc O(N)

// int main()
// {
//     vector<int> arr = {2, 6, 5, 8, 11};
//     int k = 14;
//     int n = arr.size();
//     vector<int> ans;

//     map<int,int>mp;

//     for(int i=0;i<n;i++)
//     {
//         int temp = k - arr[0];
//         if(mp.find(temp)!=mp.end())
//         {
//             return {mp[temp],i};
//         }
//         mp[arr[i]] = i;
//     }
//     for(auto it:ans)cout<<it<<" ";
// }

// optimal 2 pointer approach
// int main()
// {
//     vector<int> arr = {3,2,4};
//     int k = 6;
//     int n = arr.size();
//     vector<int> ans;
//     sort(arr.begin(),arr.end());
//     int i = 0;
//     int j = n-1;
//     while(i<j)
//     {
//         int sum = arr[i] + arr[j];
//         if(sum == k)
//         {
//             cout<<i<<" "<<j<<endl;
//             ans.push_back(i);
//             ans.push_back(j);
//             break;
//         }
//         else if(sum > k)
//         j--;
//         else i++;
//     }

//     for(auto it:ans)
//     cout<<it << " ";

// }

// sort arrays of 0,1,2
// brute force sort the array using merge sort O(nlogn) sc O(n)
// better O(2N) sc O(1)
// int main()
// {
//     vector<int> arr = {2, 0, 2, 1, 1, 0};
//     int n = arr.size();
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//             count0++;
//         else if (arr[i] == 1)
//             count1++;
//         else
//             count2++;
//     }
//     vector<int> ans;
//     for (int i = 0; i < count0; i++)
//         arr[i] = 0;
//     for (int i = count0; i < count0+count1; i++)
//         arr[i] = 1;
//     for (int i = count0+count1; i < count0+count1+count2; i++)
//         arr[i] = 2;

//         for(auto it:arr)
//         cout<<it<<" ";
// }

// optimal
// dutch national bag algorithm

// majority element
// tc O(N2)
// int main()
// {
//     vector<int>arr = {2,2,1,1,1,2,2};
//     int ans ;
//     int n = arr.size();
//     for(int i=0;i<n;i++)
//     {
//         int count = 1;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]==arr[j])
//             {
//             count ++;
//             // cout<<count;
//             ans  = arr[i];
//             }
//         }
//         if(count>n/2)
//         {
//             cout<<arr[i];
//             break;
//         }
//     }
// }

// better solution
// int main()
// {
//     vector<int>arr = {2,2,1,1,1,2,2};
//     map <int,int>mp;
//     for(int i=0;i<arr.size();i++)
//     {
//         mp[arr[i]]++;

//     }
//     int maxi = INT_MIN;
//     for(auto it:mp)
//     {
//         if(it.second > arr.size()/2)
//         maxi = it.first;
//     }
//     cout<<maxi;
// }

// optimal solution
// int main()
// {
//     vector<int> arr = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
//     int n = arr.size();
//     int count = 0;
//     int temp;
//     for (int i = 0; i < n; i++)
//     {
//         if (count == 0)
//         {
//             temp = arr[i];
//             count++;
//         }
//         if (arr[i] != temp)
//             count--;
//         else
//             count++;
//     }
//     count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == temp)
//             count++;
//         if(count>n/2)
//         cout<<temp;
//     }
//     cout<<-1;
// }





// kadanes algori 