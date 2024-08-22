#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(vector<int> arr, int k, int index, vector<int> &temp, vector<vector<int>> &ans)
{
    if (index <= 0)
    {
        if (arr[index] == k)
        {
            temp.push_back(arr[0]);
            ans.push_back(temp);
        }
        else
            return;
    }

    if (k == 0)
        ans.push_back(temp);

    // pick the element
    if(k>=arr[index])
    {
        temp.push_back(arr[index]);
        solve(arr, k - arr[index], index - 1, temp,ans);
    }
    // do not pick the element
    temp.pop_back();
    solve(arr, k, index - 1, temp,ans);
}
int main()
{
    vector<int> arr = {1, 3, 2, 4};
    int k = 4;
    vector<int> temp;
    vector<vector<int>>ans;
    solve(arr, k, arr.size() - 1, temp,ans);

    for(int i=0;i<ans.size();i++)
    {
        for(auto it:ans[i])
        cout<<it<<" ";
        cout<<endl;
    }
}