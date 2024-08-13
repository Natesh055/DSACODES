#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// find repeating and missing number
// tc O(N2)
// int main()
// {
//     vector<int>arr={4,3,6,2,1,1};
//     int n = arr.size();
//     vector<int>ans;
//     int rep=-1,mis=-1;
//     for(int i=1;i<=n;i++)
//     {
//         int count =0;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]==arr[j])
//             count++;
//         }
//         if(count==2)
//         rep = i;
//         if(count==0)
//         mis =i;

//         if(rep!=-1 && mis!=-1)
//         break;
//     }
//     cout<<mis<<" "<< rep;
// }

// better 

// int main()
// {
//      vector<int>arr={4,3,6,2,1,1};
//     int n = arr.size();
//     map<int,int>mp;
//     for(int i=0;i<n;i++)
//     {
//         mp[arr[i]]++;
//     }
//     for(auto it:mp)
//     {
//         if(it.second==2)
//             cout<<it.first<<" "<< n-it.first;
//     }
// }


// optimal solution
// TC O(N) SC O(1)
// int main()
// {
//     vector<int>arr = {4,3,6,2,1,1};
//     int n = arr.size();
//     int sum = 0;
//     int sn =(n*(n+1)/2);
//     int s2n = (n*(n+1)*(2*n+1))/6;
//     int sum2=0;
//     for(int i=0;i<n;i++)
//     {
//         sum+=arr[i];
//         sum2+=pow(arr[i],2);
//     }
//     // repeating-missing
//     int val1 = sum-sn;
//     int val2 = sum2-s2n;
//     val2 = val2/val1;

//     int x = (val1+val2)/2;
//     int y = x-val1;


// }