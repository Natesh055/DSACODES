#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// reaarrange element by sign
// tc O(N)   sc O(N)
// int main()
// {
//     vector<int> arr = {3, 1, -2, -5, 2, -4};
//     int n = arr.size();
//     vector<int> pos;
//     vector<int> neg;
//     for (auto it : arr)
//     {
//         if (it > 0)
//             pos.push_back(it);
//         else
//             neg.push_back(it);
//     }
//     int i = 0, j = 0;
//     for (int k = 0; k < n; k++)
//     {
//         if (k % 2 == 0)
//             arr[k] =  pos[i++];

//             else
//             arr[k] = neg[j++];
//     }

//     for (auto it : arr)
//     {
//         cout<<it<<" ";
//     }
// }

// optimal
int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    int n = arr.size();
    vector<int> ans(n);

    int pos = 0, neg = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i]>0)  //0,2,4,
        {
            ans[2*pos] = arr[i];
            pos++;

        }
        else{
            ans[2*neg+1] = arr[i];
            neg++;
        }
    }
    for(auto it:ans)
    cout<<it<<" ";
}