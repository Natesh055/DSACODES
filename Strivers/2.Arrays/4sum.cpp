#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;


// brute force
// TC O(N4)
// int main()
// {
//     vector<int>arr = {1,0,-1,0,-2,2};
//     int k = 0;
//     int n = arr.size();
//     set<vector<int>>st;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             for(int k=j+1;k<n;k++)
//             {
//                 for(int l=k+1;l<n;l++)
//                 {
//                     int sum = arr[i]+arr[j]+arr[k]+arr[l];
//                     if(sum==k)
//                     {
//                         vector<int>temp = {arr[i],arr[j],arr[k],arr[l]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>>ans(st.begin(),st.end());
// }


// better solution
// O(N3 logN)
// int main()
// {
//     vector<int>arr = {1,0,-1,0,-2,2};
//     int target = 0;
//     int n =arr.size();
//     set<vector<int>>st;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             set<int>hashst;
//             for(int k=j+1;k<n;k++)
//             {
//                 int sum = target-(arr[i]+arr[j]+arr[k]);
//                 if(hashst.find(sum)!=hashst.end())
//                 {
//                     vector<int>temp = {arr[i],arr[j],arr[k],sum};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 hashst.insert(arr[k]);

//             }
//         }
//     }
// }


// optimal solution
int main()
{
    vector<int>arr = {1,1,1,2,2,2,3,3,3,4,4,4,5,5};
    int target = 8;

    int n = arr.size();

    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n-3;i++)
    {
        if(i>0 && arr[i]==arr[i-1])
        continue;
        for(int j=i+1;j<n;j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1])
            continue;
            int k = j+1;
            int l = n-1;

            while(k<l)
            {
                long long sum = arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum==target)
                {
                    vector<int>temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1])k++;
                    while(k<l && arr[l]==arr[l+1])l--;
                }
                else if(sum>target)
                {
                    k++;
                }
                else
                l--;



            }

        }
    }
}