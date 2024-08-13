#include <iostream>
#include <math.h>
#include <cstring>
#include<vector>
#include <map>
#include <unordered_map>
using namespace std;

// // calculate all permutations
void solve(vector<int>arr,vector<vector<int>>&ans,vector<int>&temp,int n,vector<int>freq)
{
    if(temp.size()==n)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(!freq[i])
        {
            temp.push_back(arr[i]);
            freq[i] = 1;
            solve(arr,ans,temp,n,freq);
            freq[i] = 0;
            temp.pop_back();
        }
    }
}
int main()
{
    vector<int>arr = {1,2,3};
    int n = arr.size();
    vector<int>freq(n,0);
    vector<int>temp;
    vector<vector<int>>ans;

    solve(arr,ans,temp,n,freq);
    // computing the permutations
    for(auto it:ans)
    {
        for(int i=0;i<it.size();i++)
        cout<<it[i]<<" ";
        cout<<endl;
    }

}

// longest consecutive sequence

// O(N3)
// bool ls(vector<int> arr, int el)
// {
//     for (int i = 0; i < arr.size(); i++)
//         if (arr[i] == el)
//             return true;

//     return false;
// }
// int main()
// {
//     vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
//     int longest;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int x = arr[i];

//         int count = 1;
//         while(ls(arr,x+1)==true)
//         {
//             count++;
//             x++;
//             longest = max(longest,count);
//         }

//     }
//     cout << longest;
// }

// better
// int main()
// {
//     vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
//     int n = arr.size();
//     sort(arr.begin(),arr.end());
//     int cur = 0;
//     int lsmaller = INT_MIN;
//     int longest = 1;
//     for(int i=0;i<n;i++)
//     {
//         if(i!=0 && arr[i-1]==lsmaller -1 )
//         {
            
//         }
//     }
// }
