#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;


int main()
{
    vector<vector<int>>arr = {{1,2},{2,3},{5},{0},{5},{},{}};
    int n =arr.size();
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it:arr[i])
        {
            indegree[it]++;
        }
    }
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(auto it:arr[i])
        {
            for(int i=0;i<indegree.size();i++)
            {
                if(it==indegree[i])
                count++;
            }
        }
    }
}