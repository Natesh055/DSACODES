#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// house robber 2
int solve(vector<int>arr)
{
    int prev = arr[0];
    int prev2= 0;
    int ans = 0;
    for(int i=1;i<arr.size();i++)
    {
        int take = arr[i];
        if(i>1)
        take+= prev2;

        int nottake = prev;

        ans = max(take,nottake);
        prev2 = prev;
        prev = ans;
    }
    return prev;
}
int main()
{
    vector<int>arr = {1,2,3,1};
    
    int n = arr.size();
    if(n==1)
    return arr[0];
    vector<int>temp1;
    vector<int>temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        temp1.push_back(arr[i]);
        if(i!=n-1)
        temp2.push_back(arr[i]);
    }
int ans1 = solve(temp1);

int ans2 = solve(temp2);
int ans = max(ans1,ans2);
cout<<ans;

}