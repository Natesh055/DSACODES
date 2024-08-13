#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// finding nth root

int main()
{
    int m = 27, n = 3;
    int s = 1,e = 27;
    int ans = 0;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(pow(mid,n) == m)
        {
            ans = mid;
            break;
        }
        else if(pow(mid,n) < m)
        s= mid+1;
        else
        e = mid-1;
    }
    cout<<ans;
}