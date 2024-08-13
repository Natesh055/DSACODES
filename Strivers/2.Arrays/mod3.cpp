#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include<map>
#include<unordered_map>
using namespace std;

// find missing number in an array
// brute force O(n2)
// int main()
// {
//     vector<int>arr= {1,2,4,5};
//     int n =5;
//     for(int i=1;i<=n;i++)
//     {
//         bool flag = 0;
//         for(int j=0;j<n;j++)
//         {
//             if(arr[j] == i)
//             {
//                 flag =1;break;
//             }
//         }
//         if(flag==0)
//         cout<<i;
//     }
// }
// tc O(2N) sc O(N)
// int main()
// {
//     vector<int> arr = {3, 0, 1};
//     int n = arr.size();
//     vector<int> hash(n + 1, -1);
//     for (int i = 0; i < n; i++)
//     {
//         int temp = arr[i];
//         hash[temp] = 1;
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         if(hash[i]==-1)
//     cout<<i;
//     }
// }


// optimal solution
//  using sum
// using xor

// int main()
// {
//     vector<int>arr = {3,0,1};
//     int n  = arr.size();
//     int xor1 = 0;
//     for(int i=0;i<=n;i++)
//     xor1 = xor1^i;
//     int xor2=0;

//     for(int i=0;i<n;i++)
//     xor2 = xor2^arr[i];
//     int temp = xor1^xor2;
//     cout<<temp;

// }





// maximum consecutive 1s
// tc O(n)
// int main()
// {
//     vector<int>arr = {1,1,0,1,1,1};
//     int n = arr.size();
//     int counter = 0;
//     int maxi = 0;
//     for(int i=0;i<n;i++)
//     {   
//         if(arr[i]==1)
//         {
//             counter++;
//             if(counter > maxi)
//             maxi++;

//         }
//         else
//         counter = 0;
//     }
//     cout<<maxi;
// }




// find the number that appers once and the other numbers appear twice
// tc O(n2) sc O(1)
// int main()

// {
//      vector<int>arr = {1,1,2,3,3,4,4};
//      int n = arr.size();
//      for(int i=0;i<n;i++)
//      {
//         int flag = 0       ;
//         for(int j=0;j<n;j++)
//         {
//             if(arr[j] == arr[i])
//             {
//                 flag++;

//             }
//         }
//         if(flag == 1)
//         {
//         cout<<arr[i];
//         break;
//         }
//      }
// }


// better solution is hashing
// int main()
// {
//      vector<int>arr = {1,1,2,3,3,4,4};
//      int n = arr.size();
//      int maxi = INT_MIN;
//      for(int i=0;i<n;i++)
//      if(maxi < arr[i])
//      maxi = arr[i];

//      vector<int>hash(maxi+1,0);
//      for (int i=0;i<n;i++)
//      {
//         int num  = arr[i];
//         hash[num ]++;
//      }
//      for(int i=0;i<hash.size();i++)
//      {
//         if(hash[i]==1)
//         {
//             return hash[i];
//             break;
//         }
//      }
//      return 
// -1;
// }



// tc O(nlogm)
int main()
{
     vector<int>arr = {1,1,2,3,3,4,4};
     int n = arr.size();
     map <int,int>mp;
    for(int i=0;i<n;i++)
    mp[arr[i]]++;
    for(auto it :mp)
    if(it.second == 1)
    return it.first;
}