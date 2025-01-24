#include <iostream>

using namespace std;
//minimum subset difference


int main(){
    vector<int>arr = {1,6,11,5};
    int n = arr.size();
    int k =0;
    for(int i=0;i<n;i++)
    {
        k+=arr[i];
    }
    int n = arr.size();

    vector<vector<bool>>dp(n,vector<bool>(k+1,false));

    for(int i=0;i<n;i++)
    {
        dp[i][0] = true;
    }
    if(arr[0]<=k)
        dp[0][arr[0]] = true;





}