#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//assign cookies
int main()
{
    vector<int>greed = {1,5,3,3,4};
    vector<int>s = {4,2,1,2,1,3};
    sort(greed.begin(),greed.end());
    sort(s.begin(),s.end());
    int n = greed.size();
    int count=0;
    int i,j=0;
    while(i<n&&j<n){
        if(greed[i] <= s[j]){
            i++;
        }
        j++; 
    }
    cout<<i;
}