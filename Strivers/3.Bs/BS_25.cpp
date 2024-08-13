#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// O(N*log(M))
w
int main()

{
    vector<vector<int>>arr = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int k = 5;
    int m = arr.size();
    int n = arr[0].size();  
    for(int i=0;i<m;i++)
    {
        if(bs(arr[i],k))
        {
            cout<<1;
            break;
        }
    }
    cout<<0;

}