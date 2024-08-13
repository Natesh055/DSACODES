#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
using namespace std;

// left rotate by k places
// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
//                       // 0,1,2,3,4,5,6
//     int k = 3%arr.size();
//     vector<int> temp;
//     for (int i = 0; i < k; i++)
//     {
//         temp.push_back(arr[i]);
//     }

//     for (int i = k; i < arr.size(); i++)
//     {
//         arr[i - k] = arr[i];
//         // cout << arr[i] << " ";
//     }
//     int index = 0;
//     for (int i = arr.size() -k; i < arr.size(); i++)
//     {
//         arr[i] = temp[i-(n-k)];
//     }

//     for (auto it : arr)
//         cout << it << " ";
// }

// int main()
// {
//                     //[5,6,7,1,2,3,4]
//     vector<int> arr = {-1,-100,3,99};
//     //              // 0,1,2,3,4,5,6

//     int k = 2;

//     int n  = arr.size();
//     vector<int>temp;

//     for(int i =n-k;i<n;i++)
//     temp.push_back(arr[i]);

//     for(int i=n-1;i>=k;i--)
//     {
//         arr[i] = arr[i-k];
//     }
//     for(int i=0;i<k;i++)
//     arr[i] = temp[i];

//     for(auto it :arr)cout<<it<<" ";

// }

// move 0s
// int main()
// {
//     vector<int> arr = {0};
//     int n = arr.size();
// bute force TC O(2* N) SC O(N)
// vector<int> temp;
// for (int i = 0; i < n; i++)
//     if (arr[i] != 0)
//         temp.push_back(arr[i]);

// for(int i=0;i<n;i++)
// {
//     if(i>=temp.size())
//     arr[i] = 0;
//     else
//     arr[i] = temp[i];
// }

// optimal 2 pointer approach
// int j = -1;
// for(int i=0;i<n;i++)
// {
//     if(arr[i]==0)
//     j = i;
//     break;
// }

// for (int i = j+1; i < n; i++)
// {
//     if(arr[i]!=0 )
//     {
//         swap(arr[i],arr[j]);
//         j++;
//     }
// }
//     for (auto it : arr)
//         cout << it << " ";
// }

// find union of 2 arrays
// int main()
// {
//     vector<int> temp1 = {1, 1, 2, 3, 4, 5};
//     vector<int> temp2 = {2, 3, 4, 4, 5, 6};
//     vector<int> un;

//     int n = 6;
//     int i = 0;
//     int j = 0;
//     while (i < n && j < n)
//     {
//         if (temp1[i] > temp2[j])
//         {
//             if (un.back() != temp2[j])
//                 un.push_back(temp2[j++]);
//         }

//         else if (temp1[i] < temp2[j])
//         {
//             if (un.back() != temp1[i])
//                 un.push_back(temp1[i++]);
//         }

//         else
//         {
//             if (un.back() != temp1[i])
//             un.push_back(temp1[i]);
//             i++;
//             j++;
//         }
//     }
//     for (auto it : un)
//         cout << it << " ";
// }

// intersection

int main()
{
    vector<int> temp1 = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> temp2 = {2, 3, 3, 5, 6, 6, 7};
    int n1 = temp1.size();
    int n2 = temp2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j])
        {
            i++;
        }
        else if (temp1[i] > temp2[i])
            j++;

        else
        {
            ans.push_back(temp1[i]);
            i++;
            j++;
        }
    }

    for (auto it : ans)
        cout << it << " ";
}