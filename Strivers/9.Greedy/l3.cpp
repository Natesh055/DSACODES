#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// shortest job first
int main()
{
    vector<int>arr = {4,3,7,1,2};
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int time = 0;
    int wt = 0;
    for(int i=0;i<n;i++)
    {
        wt+=time;
        time+=arr[i];
    }
    cout<< wt/n; 
}