#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// best time to buy and sell stocks
int main()
{
    vector<int>arr = {7,1,5,3,6,4};
    int n = arr.size();
    int mini = arr[0];
    int profit = 0;
    for(int i=1;i<n;i++)
    {
        int cost = arr[i] - mini;
        profit = max(profit,cost);
        mini = min(mini,arr[i]);
    }
    cout<<profit;
}