#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// merge overlapping subintervals
// TC O(nlogn+2n)

// int main()
// {
//     vector<vector<int>>arr ={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
//     sort(arr.begin(),arr.end());

//     vector<vector<int>>ans;

//     int n = arr.size();
//     for(int i=0;i<n;i++)
//     {
//         int start = arr[i][0];
//         int end = arr[i][1];

//         if(!ans.empty() && end<=ans.back()[1])
//         continue;

//         for(int j=i+1;j<n;j++)
//         {
//             if(end >=arr[j][0])
//             {
//                 end = max(end,arr[j][1]);
//             }
//             else 
//             break;

//         }
//         ans.push_back({start,end});

//     }
//     for(int i=0;i<ans.size();i++)
//     {
//         for(auto j:ans[i])
//         {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }

int main()
{
    vector<vector<int>>arr ={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        if(ans.empty()||arr[i][0]> ans.back()[1])
        ans.push_back({arr[i][0],arr[i][1]});
        else
        {
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
            
        }


    }
}