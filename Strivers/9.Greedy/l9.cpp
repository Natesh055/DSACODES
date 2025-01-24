#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// insert intervals

int main()
{
    vector<vector<int>>intervals = {
        {1,2},{3,4},{5,7},{8,10},{12,16}
    };
    vector<int>newinterval = {6,8};
    int sp = newinterval[0];
    int ep = newinterval[1];

    vector<vector<int>>result;
    int i=0;
    int n = intervals.size();
    while(i<n && intervals[i][1] < sp){
        result.push_back(intervals[i]);
        i++;
    }
    while(i<n && intervals[i][0] < ep)
    {
        newinterval[0]= min(newinterval[0],intervals[i][0]);
        newinterval[1]= max(newinterval[1],intervals[i][1]);
        i++;
    }
    result.push_back(newinterval);
    while(i<n)
    {
        result.push_back(intervals[i]);
        i++;
    }


}