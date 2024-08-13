#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// majority element n/3 times

// int main()
// {
//     // vector<int>arr = {1,1,1,3,3,2,2,2};
//     vector<int> arr = {3, 2, 2, 2, 3};
//     int n = arr.size();
//     // at max we can only have 2 elements
//     vector<int> ans;
//     int floor = n / 3;
//     for (int i = 0; i < n; i++)
//     {
//         if (ans.size() == 0 || ans.back() != arr[i])
//         {

//             int count = 1;
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (arr[i] == arr[j])
//                     count++;
//             }
//             if (count > floor)
//                 ans.push_back(arr[i]);
//         }
//     }
//     for (auto it : ans)
//         cout << it << " ";
// }

// better approach hashing
int main()
{
vector<int>arr = {1,1,1,3,3,2,2,2};
int n = arr.size();
vector<int>ans;

map<int,int>mp;
for(int i=0;i<n;i++)
{
    mp[arr[i]]++;
}
for(auto it:mp)
{
    if(it.second>n/3)
        ans.push_back(it.first);   
}


}